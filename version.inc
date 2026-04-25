<?php
// deployeddave fork - v3.0
// Changes from 2.1:
//   - Fixed PARITY setting never being saved (was overwriting STOP_BITS)
//   - Fixed Optoma Power OFF byte: \x30 -> \x32 for lamp-based models
//   - Fixed broken double-backslash in Optoma_X600 HDMI2 command
//   - Fixed unreachable exit(0) calls after break in processSequenceName()
//   - Added FPP 8.x, 9.x, 10.x version blocks to pluginInfo.json
//   - Added 11 new projector entries: BenQ TK850/W2700/TK700STi,
//     Epson ESC/VP21 business and home theatre, NEC P627UL/PE506UL/ME403U,
//     ViewSonic PX701/PX728, Optoma GT1080HDR, Optoma Laser ZH/ZU/UHD,
//     Panasonic PT-VMZ/PT-MZ
//   - Added Optoma EP7xx RS232 entry from official PDF spec
//   - plugin_setup.php: serial fields always visible (no projector required)
//   - plugin_setup.php: connection status widget
//   - plugin_setup.php: help button linking to help/plugin_setup.php
//   - plugin_setup.php: corrected bug report URL to deployeddave fork
//   - plugin_setup.php: default baud rate corrected from 19200 to 9600
//   - Added help/plugin_setup.php - full F1-integrated help documentation
//   - menu.inc: modern FPP menu format replacing output_menu.inc
//   - commonFunctions.inc.php: gitURL corrected to deployeddave fork
//   - proj.php: error reporting cleaned up for production
//   - proj.php: TCP socket read timeout added to prevent hangs
//   - fpp_install.sh: udev rule for persistent serial permissions
$VERSION = "3.0";
?>
