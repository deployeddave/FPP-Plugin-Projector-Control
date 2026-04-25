<h3>Projector Control Plugin — Help</h3>

<style>
.pc-help h4       { margin: 18px 0 6px; font-size: 14px; color: #d4a843; }
.pc-help h5       { margin: 14px 0 4px; font-size: 13px; font-weight: bold; }
.pc-help p        { margin: 0 0 10px; font-size: 13px; line-height: 1.6; }
.pc-help ul,
.pc-help ol       { margin: 0 0 10px 20px; font-size: 13px; line-height: 1.7; }
.pc-help table    { width: 100%; border-collapse: collapse; margin: 8px 0 14px; font-size: 13px; }
.pc-help th       { background: #2a2a2a; text-align: left; padding: 6px 10px;
                    border-bottom: 2px solid #444; font-size: 11px; text-transform: uppercase;
                    letter-spacing: .05em; color: #aaa; }
.pc-help td       { padding: 6px 10px; border-bottom: 1px solid #333; vertical-align: top; }
.pc-help tr:last-child td { border-bottom: none; }
.pc-help code     { background: #1a1a1a; border: 1px solid #444; padding: 1px 5px;
                    border-radius: 3px; font-size: 12px; color: #7ec8e3; font-family: monospace; }
.pc-help pre      { background: #111; border: 1px solid #444; border-radius: 4px;
                    padding: 10px 14px; font-size: 12px; overflow-x: auto;
                    margin: 6px 0 12px; font-family: monospace; line-height: 1.5; color: #ccc; }
.pc-help .note    { background: #1a2535; border-left: 3px solid #4a8ec2;
                    padding: 8px 12px; margin: 10px 0; font-size: 13px; border-radius: 0 4px 4px 0; }
.pc-help .warn    { background: #2a1e0a; border-left: 3px solid #d4a843;
                    padding: 8px 12px; margin: 10px 0; font-size: 13px; border-radius: 0 4px 4px 0; }
.pc-help .tip     { background: #0a2a1a; border-left: 3px solid #4ab87a;
                    padding: 8px 12px; margin: 10px 0; font-size: 13px; border-radius: 0 4px 4px 0; }
.pc-help hr       { border: none; border-top: 1px solid #333; margin: 18px 0; }
</style>

<div class="pc-help">

<!-- ═══════════════ OVERVIEW ══════════════ -->
<h4>Overview</h4>
<p>The Projector Control plugin allows FPP to automatically power on, power off, switch inputs,
mute, freeze, and perform other operations on a connected projector — synchronized with your
light show playlists. Three connection types are supported:</p>
<ul>
  <li><b>Serial / RS232</b> — USB-to-serial adapter on the Pi connected to the projector's DB9 port (most common)</li>
  <li><b>TCP/IP Network</b> — RS232-equivalent commands sent over a LAN connection</li>
  <li><b>PJLink</b> — Open industry-standard IP control protocol (requires Net::PJLink Perl library)</li>
</ul>

<!-- ═══════════════ REQUIREMENTS ══════════════ -->
<hr>
<h4>Requirements</h4>
<h5>For Serial (RS232)</h5>
<ul>
  <li>A projector with a DB9 RS232 serial control port</li>
  <li>A USB-to-serial adapter — <b>FTDI FT232R/RL chip strongly recommended</b> (Prolific PL2303 and CH340 chips can cause intermittent failures on Pi)</li>
  <li>A DB9 straight-through serial cable (female-to-female)</li>
  <li>Possibly a null-modem adapter — required by some projectors if commands are sent but ignored</li>
</ul>
<h5>For Network (TCP/IP or PJLink)</h5>
<ul>
  <li>Projector connected to your LAN with network control enabled in its OSD menu</li>
  <li>Projector's static IP address and control port number</li>
  <li>For PJLink: the <code>Net::PJLink</code> Perl library (installed automatically by <code>fpp_install.sh</code>)</li>
</ul>

<!-- ═══════════════ INSTALLATION ══════════════ -->
<hr>
<h4>Installation</h4>
<p>Install via <b>Content Setup → Plugin Manager</b>. The install script sets serial port permissions
and installs the Net::PJLink library via CPAN — this may take 2–5 minutes on first install.
Reboot when prompted to complete setup.</p>

<!-- ═══════════════ HARDWARE SETUP ══════════════ -->
<hr>
<h4>Serial Hardware Setup</h4>
<p>Connect: <b>Pi USB port → USB-to-serial adapter → DB9 cable → Projector RS232 port</b></p>
<p>After plugging in the adapter, verify it is detected:</p>
<pre>ls /dev/ttyUSB*</pre>
<p>You should see <code>/dev/ttyUSB0</code>. If nothing appears, try a different USB port or adapter.
To confirm which chip was loaded:</p>
<pre>dmesg | grep -i "usb\|tty" | tail -20</pre>

<div class="warn"><b>⚠ Null Modem Adapter:</b> If the Pi sees the device but the projector never responds,
try adding a null-modem (crossover) adapter between the cable and the projector. This crosses
the TX/RX lines and is required by some projectors.</div>

<div class="warn"><b>⚠ Device Name Can Change:</b> <code>/dev/ttyUSB0</code> can become <code>/dev/ttyUSB1</code>
after a reboot if you add other USB devices. Use <code>ls /dev/serial/by-id/</code> to find the
persistent device path for a stable alternative.</div>

<!-- ═══════════════ PLUGIN CONFIG ══════════════ -->
<hr>
<h4>Plugin Configuration</h4>
<table>
  <tr><th>Field</th><th>Description</th></tr>
  <tr><td><b>Enable Plugin</b></td><td>Must be ON for any commands to work. If OFF, all projector scripts exit silently.</td></tr>
  <tr><td><b>Projector</b></td><td>Select your model. Changing this and clicking Save regenerates all command scripts automatically.</td></tr>
  <tr><td><b>Serial Device</b></td><td>The <code>/dev/ttyUSB*</code> device for your adapter. Only shown for serial projectors.</td></tr>
  <tr><td><b>Baud Rate</b></td><td>Must match your projector's RS232 setting exactly. Most projectors use 9600. Check your projector's manual or OSD. Default shown in UI (19200) is not correct for most models.</td></tr>
  <tr><td><b>Char Bits / Stop Bits / Parity</b></td><td>Almost universally 8 / 1 / none for all projectors.</td></tr>
  <tr><td><b>Projector IP</b></td><td>For TCP/IP and PJLink projectors only. Use a static IP.</td></tr>
  <tr><td><b>Password</b></td><td>For PJLink projectors with a password set. Leave blank if none.</td></tr>
  <tr><td><b>Port</b></td><td>For TCP projectors only. Check your projector's manual (common: 4352, 3629, 7142, 8000, 23).</td></tr>
</table>

<div class="warn"><b>⚠ Always click Save after any change.</b> Save triggers script regeneration —
without it the old scripts remain in place regardless of what you changed in the UI.</div>

<!-- ═══════════════ HOW SCRIPTS WORK ══════════════ -->
<hr>
<h4>How Commands Work</h4>
<p>When you click Save, the plugin reads every command key in your projector's entry
(ON, OFF, HDMI1, AV_MUTE_ON, etc.) and generates a shell script for each one.
Those scripts appear in FPP's Command system with names like
<b>Projector Control-Projector ON</b>, <b>Projector Control-Projector HDMI1</b>, etc.
The key name in <code>projectorCommands.inc</code> is the display name — nothing else controls it.</p>

<p>Scripts are written to two locations:</p>
<pre>/home/fpp/media/scripts/PROJECTOR-ON.sh
/home/fpp/media/plugins/FPP-Plugin-Projector-Control/commands/PROJECTOR-ON.sh</pre>

<!-- ═══════════════ USING IN SHOWS ══════════════ -->
<hr>
<h4>Using Commands in Your Show</h4>
<p>After saving, projector commands appear automatically in:</p>
<ul>
  <li><b>Content Setup → Command Presets</b> — create a preset using Run Script → select PROJECTOR-*.sh</li>
  <li><b>Playlist entries</b> — add a Script item at the desired playlist position</li>
  <li><b>FPP Triggers / GPIO</b> — attach to physical button inputs</li>
  <li><b>Scheduler</b> — run a playlist with projector commands on a fixed daily schedule</li>
</ul>

<p><b>Recommended show timing for lamp projectors:</b></p>
<table>
  <tr><th>Time</th><th>Action</th><th>Notes</th></tr>
  <tr><td>T−2:00</td><td>Power ON</td><td>Lamp warm-up (30–90 sec needed)</td></tr>
  <tr><td>T−0:30</td><td>Switch to show input</td><td>Confirm correct source is active</td></tr>
  <tr><td>T−0:00</td><td>Show starts</td><td>Lights + projector in sync</td></tr>
  <tr><td>Show end</td><td>Power OFF</td><td>Projector runs its own cool-down fan cycle</td></tr>
</table>

<div class="tip"><b>✓ AV Mute vs Power Off:</b> For blanking the image between segments, use AV_MUTE_ON
rather than cycling power. The image blanks and restores instantly with no thermal stress on the
lamp. Power Off is for end-of-night only.</div>

<div class="tip"><b>✓ Safety net:</b> Enable the projector's built-in Auto Power Off in its OSD
(15–30 min no-signal). If the RS232 OFF command ever fails, the projector shuts itself down
rather than running all night.</div>

<!-- ═══════════════ ADDING YOUR PROJECTOR ══════════════ -->
<hr>
<h4>Adding Your Projector</h4>
<p>If your model isn't in the list, edit <code>projectorCommands.inc</code> and add an Array block
immediately before the final <code>Array("NAME" => "-- Select Projector --",</code> line.
Find your projector's RS232 command table in its manual or by searching
<i>"[brand] [model] RS232 command table"</i>.</p>
<p>Each hex byte from the table becomes <code>\xNN</code> in the PHP string. For example,
hex bytes <code>7E 30 30 30 30 20 31 0D</code> become <code>"\x7E\x30\x30\x30\x30\x20\x31\x0D"</code>.</p>
<pre>Array("NAME" => "Your_Projector_Model",
    "ON"        => "\x7E\x30\x30\x30\x30\x20\x31\x0D",
    "OFF"       => "\x7E\x30\x30\x30\x30\x20\x30\x0D",
    "HDMI1"     => "\x7E\x30\x30\x31\x32\x20\x31\x0D",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),</pre>
<p>After editing the file, click Save on this page to regenerate the command scripts.</p>

<!-- ═══════════════ BAUD RATES ══════════════ -->
<hr>
<h4>Common Baud Rates by Manufacturer</h4>
<table>
  <tr><th>Manufacturer / Series</th><th>Default Baud</th></tr>
  <tr><td>Optoma (older lamp models)</td><td>9600</td></tr>
  <tr><td>Optoma (GT1080HDR, modern lamp)</td><td>9600</td></tr>
  <tr><td>Optoma (laser — ZH / ZU / UHD series)</td><td>19200</td></tr>
  <tr><td>BenQ (modern — TK850, W2700, TK700STi)</td><td>9600</td></tr>
  <tr><td>BenQ (MX819ST, W770ST)</td><td>115200</td></tr>
  <tr><td>Epson (all ESC/VP21 models)</td><td>9600</td></tr>
  <tr><td>NEC (modern laser — P627UL, PE506UL)</td><td>38400</td></tr>
  <tr><td>Panasonic (all PT series)</td><td>9600</td></tr>
  <tr><td>ViewSonic (PX 4K series)</td><td>9600</td></tr>
  <tr><td>ViewSonic (PJD series)</td><td>115200</td></tr>
  <tr><td>Hitachi / Dukane</td><td>19200</td></tr>
</table>

<!-- ═══════════════ TESTING ══════════════ -->
<hr>
<h4>Testing Commands</h4>
<p>Run the generated script directly from SSH to test:</p>
<pre>bash /home/fpp/media/scripts/PROJECTOR-ON.sh</pre>
<p>Or call proj.php directly:</p>
<pre>/usr/bin/php /home/fpp/media/plugins/FPP-Plugin-Projector-Control/proj.php -dSERIAL -s/dev/ttyUSB0 -cON</pre>
<p>To test the serial port at a raw level (bypasses the plugin entirely):</p>
<pre>stty -F /dev/ttyUSB0 9600 raw -echo
printf '\x7E\x30\x30\x30\x30\x20\x31\x0D' > /dev/ttyUSB0</pre>

<!-- ═══════════════ LOG FILE ══════════════ -->
<hr>
<h4>Log File</h4>
<p>Every command sent is logged. View it with:</p>
<pre>tail -f /home/fpp/media/logs/FPP-Plugin-Projector-Control.log</pre>
<p>A successful command shows <code>RETURN DATA: ... 50 [P]</code> — hex 50 is ASCII "P" (Pass).
<code>46 [F]</code> means the projector returned Fail (wrong command or wrong baud rate).</p>

<!-- ═══════════════ TROUBLESHOOTING ══════════════ -->
<hr>
<h4>Troubleshooting</h4>
<table>
  <tr><th>Symptom</th><th>Check</th></tr>
  <tr><td>Log: "Plugin is DISABLED"</td><td>Enable Plugin checkbox is OFF — enable and Save</td></tr>
  <tr><td>Log: "No Projector configured"</td><td>No projector selected or Save was not clicked</td></tr>
  <tr><td>Log: "projector command not found"</td><td>Script was generated for a different projector — Save again with correct projector selected</td></tr>
  <tr><td>No device in Serial Device dropdown</td><td>Adapter not detected — run <code>ls /dev/ttyUSB*</code>; try different USB port or FTDI adapter</td></tr>
  <tr><td>Device found but projector silent</td><td>1) Check baud rate matches projector OSD &nbsp; 2) Try null-modem adapter &nbsp; 3) Confirm RS232 enabled in projector OSD &nbsp; 4) Check projector has standby power</td></tr>
  <tr><td>Works manually, not in playlist</td><td>Check plugin is enabled; verify device name hasn't changed; add delay between back-to-back commands</td></tr>
  <tr><td>PJLink fails with Perl error</td><td>Run <code>perl -e "use Net::PJLink"</code> — if error, reinstall: <code>PERL_MM_USE_DEFAULT=1 sudo cpan install Net::PJLink</code></td></tr>
  <tr><td>Network projector reachable but no response</td><td>Enable "Network in Standby" in projector OSD; verify port number; test with <code>nc [ip] [port]</code></td></tr>
</table>

<p style="margin-top:16px; font-size:12px; color:#666;">
  FPP Projector Control Plugin — deployeddave fork &nbsp;|&nbsp;
  <a href="https://github.com/deployeddave/FPP-Plugin-Projector-Control" target="_blank">GitHub</a> &nbsp;|&nbsp;
  Originally by Ben Shaver (bshaver) and Pat Delaney (patdelaney)
</p>

</div>
