#!/bin/bash
#
# fpp_install.sh — FPP-Plugin-Projector-Control (deployeddave fork)
#
# Run automatically by FPP's plugin installer after git clone.
# Also safe to run manually to repair permissions or reinstall Net::PJLink.

pushd $(dirname $(which $0))
target_PWD=$(readlink -f .)

# Register plugin with FPP
/opt/fpp/scripts/update_plugin ${target_PWD##*/}

# ── Serial port permissions ───────────────────────────────────────────────────
# The original plugin used: sudo chmod a+w /dev/tty*
# That works at install time but resets on every reboot because /dev entries
# are recreated by udev from scratch.
#
# The correct fix is to add the 'fpp' user to the 'dialout' group, which is
# the standard Linux mechanism for permanent serial port access. The group
# membership persists across reboots with no udev rule needed.
#
# We also write a udev rule as a belt-and-suspenders backup for systems where
# group membership alone doesn't cover dynamically-created ttyUSB devices
# (some minimal/embedded Linux configurations).

echo ; echo "Setting up serial port permissions..." ; echo

# Method 1: Add fpp user to dialout group (persistent across reboots)
if id -nG fpp | grep -qw dialout; then
    echo "fpp user is already in the dialout group."
else
    /usr/bin/sudo /usr/sbin/usermod -a -G dialout fpp
    echo "Added fpp user to dialout group."
    echo "Note: Group membership takes effect after the next reboot or re-login."
fi

# Method 2: udev rule for USB serial adapters (belt-and-suspenders)
# This rule sets group ownership to 'dialout' and grants rw for any ttyUSB
# or ttyACM device as soon as it is plugged in, before any daemon accesses it.
UDEV_RULE='/etc/udev/rules.d/99-fpp-serial.rules'
if [ ! -f "$UDEV_RULE" ]; then
    echo 'SUBSYSTEM=="tty", KERNEL=="ttyUSB[0-9]*", GROUP="dialout", MODE="0664"' | \
        /usr/bin/sudo tee "$UDEV_RULE" > /dev/null
    echo 'SUBSYSTEM=="tty", KERNEL=="ttyACM[0-9]*", GROUP="dialout", MODE="0664"' | \
        /usr/bin/sudo tee -a "$UDEV_RULE" > /dev/null
    /usr/bin/sudo udevadm control --reload-rules
    /usr/bin/sudo udevadm trigger
    echo "udev rule written to $UDEV_RULE"
else
    echo "udev rule already exists at $UDEV_RULE — skipping."
fi

# ── Net::PJLink ───────────────────────────────────────────────────────────────
echo ; echo "Checking for Net::PJLink Perl library..." ; echo

if perl -e "use Net::PJLink" 2>/dev/null; then
    echo "Net::PJLink is already installed."
else
    echo "Installing Net::PJLink via CPAN (this may take a few minutes)..."
    PERL_MM_USE_DEFAULT=1 cpan install Net::PJLink
fi

# ── Schedule FPP restart ──────────────────────────────────────────────────────
setSetting restartFlag 1

echo ; echo "Projector Control plugin install complete." ; echo
echo "If this is a first install, please reboot to activate group permissions." ; echo

popd
