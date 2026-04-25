# FPP Projector Control Plugin

Control your projector from [Falcon Player (FPP)](https://github.com/FalconChristmas/fpp) — power on/off, switch inputs, mute, freeze, and more — automatically synchronized with your light show playlists.

This is the **deployeddave** fork of the original [FalconChristmas/FPP-Plugin-Projector-Control](https://github.com/FalconChristmas/FPP-Plugin-Projector-Control) plugin by Ben Shaver (bshaver) and Pat Delaney (patdelaney). It includes bug fixes, additional projector support, FPP 8/9/10 compatibility, and improved setup UX.

---

## Features

- Power projector on/off synchronized with show playlists
- Switch input sources (HDMI1, HDMI2, VGA, etc.)
- AV Mute / image blank without full power cycle
- Freeze frame and audio mute support
- Three connection methods: **RS232 Serial**, **TCP/IP Network**, **PJLink**
- Connection status widget on the settings page — shows detected/not detected at page load
- Serial settings always visible — configure without projector connected
- Full in-app help documentation (F1 or Help button on settings page)
- FPP Commands integration — commands appear in playlists, presets, triggers, and scheduler

---

## Supported FPP Versions

| FPP Version | Status |
|---|---|
| 2.x – 6.x | Supported |
| 7.x | Supported |
| 8.x | Supported |
| 9.x | Supported |
| 10.x | Supported |

---

## Supported Projectors

### Optoma
| Entry Name | Protocol | Baud |
|---|---|---|
| Optoma_150S | Serial | 9600 |
| Optoma_X600 | Serial | 9600 |
| Optoma_H181X_GT760 | Serial | 9600 |
| Optoma_XW305_ST | Serial | 9600 |
| Optoma_XW306_ST | Serial | 9600 |
| Optoma_EX525 | Serial | 9600 |
| Optoma_EP7xx_RS232 | Serial | 9600 |
| Optoma_GT1080HDR | Serial | 9600 |
| Optoma_Laser_Modern_ZH_ZU_UHD | Serial | 19200 |

### BenQ
| Entry Name | Protocol | Baud |
|---|---|---|
| BenQ_MX613ST | Serial | 9600 |
| BenQ_TK850_TK850i | Serial | 9600 |
| BenQ_W2700_HT3550 | Serial | 9600 |
| BenQ_TK700STi | Serial | 9600 |
| BenQ_MX819ST | Serial | 115200 |
| BenQ_W770ST_MS510_TH671ST | Serial | 115200 |

### Epson
| Entry Name | Protocol | Baud |
|---|---|---|
| Epson_Modern_ESC_VP21_Business | Serial | 9600 |
| Epson_HomeTheater_ESC_VP21 | Serial | 9600 |

### NEC / Sharp-NEC
| Entry Name | Protocol | Baud |
|---|---|---|
| NEC_NP400 | Serial | 38400 |
| NEC_MT1050 | Serial | 19200 |
| NEC_P627UL_P547UL | Serial | 38400 |
| NEC_PE506UL_PE506WL | Serial | 38400 |
| NEC_ME403U_ME423W_ME453X | Serial | 38400 |

### ViewSonic
| Entry Name | Protocol | Baud |
|---|---|---|
| ViewSonic_PJD7828HDL | Serial | 115200 |
| ViewSonic_PX701_4K | Serial | 9600 |
| ViewSonic_PX728_4K_PX748_4K | Serial | 9600 |

### Panasonic
| Entry Name | Protocol | Baud |
|---|---|---|
| Panasonic_PT_VMZ_Series | Serial | 9600 |
| Panasonic_PT_MZ_Large_Venue | Serial | 9600 |

### Hitachi / Dukane / Others
| Entry Name | Protocol | Baud |
|---|---|---|
| Hitachi_CP_WX3030WN | Serial | 19200 |
| Dukane_ImagePro_8972W | TCP | 23 |
| Samsung_MDC | Serial | 9600 |
| Sanyo_EIKI | Serial | 19200 |
| Mitsubishi | Serial | 9600 |
| Casio | Serial | 19200 |
| PJLINK | PJLink | N/A |

---

## Installation

### Via FPP Plugin Manager (recommended)
1. Go to **Content Setup → Plugin Manager** in the FPP web UI
2. Look for a field at the bottom of the Plugin Manager page that says something like "Install Plugin from URL" or "Add Plugin from URL."
3. Paste https://raw.githubusercontent.com/deployeddave/FPP-Plugin-Projector-Control/master/pluginInfo.json URL there and click Install (or Add/Download).
4. Restart FPP when prompted (or manually after install completes)
5. After restart,  Go to **Content Setup → Plugin Manager** and confirm Projector Control is installed

### Manual install (this fork)
```bash
cd /home/fpp/media/plugins
git clone https://github.com/deployeddave/FPP-Plugin-Projector-Control.git FPP-Plugin-Projector-Control
cd FPP-Plugin-Projector-Control
bash fpp_install.sh
```
Restart FPP

### Update an Existing Install (If Already Installed from Original Repo)
If you previously installed the original FalconChristmas version:
```bash
bashcd /home/fpp/media/plugins/FPP-Plugin-Projector-Control

#Check which remote it's currently pointing at

git remote -v

#If it's pointing at FalconChristmas, change it to your fork

git remote set-url origin https://github.com/deployeddave/FPP-Plugin-Projector-Control.git

#Pull your changes

git pull origin master
```
Then restart FPPD.

---

### Post-Install Checklist
Once installed, run through these quickly:


 Plugin appears in the Plugin Manager as installed
 
 Plugin setup page loads at Content Setup → Projector Control (or similar)
 
 Help button works and opens help/plugin_setup.php
 
 F1 key on the setup page opens help
 
 Configure your projector type, connection type (serial or TCP), and port
 
 Save settings — confirm .sh scripts generate in /home/fpp/media/scripts/ (look for PROJECTOR-*.sh files)
 
 Test Power ON command — confirm projector responds
 
 Test Power OFF command — confirm projector responds (this was the \x32 bug fix — worth validating it actually works now)
 

### Quick Verification Commands (SSH)
bash# 
Confirm plugin files are present
```bash
ls /home/fpp/media/plugins/FPP-Plugin-Projector-Control/
```

### Confirm scripts generated after saving settings

ls -la /home/fpp/media/scripts/PROJECTOR*


### Check FPP logs if something isn't working
```bash
tail -f /var/log/fppd.log
```


## Hardware Requirements

### Serial / RS232
- Projector with DB9 RS232 control port
- **FTDI FT232R/RL USB-to-serial adapter** (recommended — Prolific PL2303 and CH340 chips are unreliable on Pi)
- DB9 straight-through serial cable (female-to-female)
- Null-modem adapter may be required for some projectors

### Network (TCP/IP or PJLink)
- Projector connected to LAN with network control enabled in OSD
- Static IP address configured on projector
- Control port number from projector manual

---

## Quick Setup

1. Connect your USB-to-serial adapter and serial cable to the projector
2. Open **Content Setup → Projector Control** in FPP
3. Check the connection status widget — it should show **Connected** (green) if the adapter is detected
4. Select your projector from the dropdown
5. Verify baud rate matches your projector's serial settings
6. Click **Save**
7. Projector commands now appear in FPP's Command system as **Projector Control-Projector ON**, **Projector Control-Projector OFF**, etc.
8. Add these commands to your playlists or Command Presets

Press **F1** or click the **Help** button on the settings page for complete documentation including cable wiring, baud rate reference, CLI testing commands, troubleshooting, and FAQ.

---

## Adding Your Projector

If your model isn't in the list, edit `projectorCommands.inc` and add an Array block before the final `"-- Select Projector --"` entry. You'll need the RS232 command table from your projector's manual.

Each hex byte becomes `\xNN` in the PHP string. For example, hex `7E 30 30 30 30 20 31 0D` becomes `"\x7E\x30\x30\x30\x30\x20\x31\x0D"`.

```php
Array("NAME" => "Your_Projector_Model",
    "ON"        => "\x7E\x30\x30\x30\x30\x20\x31\x0D",
    "OFF"       => "\x7E\x30\x30\x30\x30\x20\x30\x0D",
    "HDMI1"     => "\x7E\x30\x30\x31\x32\x20\x31\x0D",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),
```

After editing, click **Save** on the settings page to regenerate command scripts.

Please open a [GitHub issue](https://github.com/deployeddave/FPP-Plugin-Projector-Control/issues) to share new projector entries so they can be included for everyone.

---

## Troubleshooting

| Symptom | Check |
|---|---|
| Log: "Plugin is DISABLED" | Enable Plugin checkbox is OFF |
| Log: "No Projector configured" | No projector selected or Save not clicked |
| Serial device not in dropdown | Adapter not detected — `ls /dev/ttyUSB*` |
| Device found but projector silent | Check baud rate; try null-modem adapter; verify RS232 enabled in projector OSD |
| PJLink fails with Perl error | `perl -e "use Net::PJLink"` — reinstall if error |
| Network projector unreachable | Enable "Network in Standby" in projector OSD |

Log file: `/home/fpp/media/logs/FPP-Plugin-Projector-Control.log`

---

## Changelog

### v3.0 (deployeddave fork)
- **Bug fix:** PARITY setting was never saved — it was overwriting STOP_BITS instead (`WriteSettingToFile` target key was wrong)
- **Bug fix:** Optoma Power OFF byte corrected from `\x30` to `\x32` for 5 lamp-based models (per RS232 spec `~XX00 2 = Power OFF`)
- **Bug fix:** Broken double-backslash `\\x35` in Optoma_X600 HDMI2 command fixed
- **Bug fix:** Unreachable `exit(0)` calls after `break` in `processSequenceName()` removed
- **Bug fix:** `proj.php` conflicting `error_reporting()` calls cleaned up for production
- **Bug fix:** TCP `sendTCP()` now sets a 3-second read timeout — previously hung indefinitely if projector connected but never responded
- **Improvement:** Serial fields always visible on settings page — no longer hidden until a projector is connected and saved
- **Improvement:** Connection status widget on settings page — shows serial adapter detected or network reachable at page load
- **Improvement:** Help button on settings page links to full in-app documentation
- **Improvement:** F1 key on settings page opens help documentation (via `help/plugin_setup.php`)
- **Improvement:** `menu.inc` modernized to FPP 7+ format — Projector Control Help now appears in FPP Help menu dropdown
- **Improvement:** `fpp_install.sh` now adds `fpp` user to `dialout` group and writes a udev rule for persistent serial permissions across reboots
- **Improvement:** Default baud rate in UI corrected from 19200 to 9600
- **Improvement:** Bug report URL corrected to deployeddave fork
- **Improvement:** `gitURL` in `commonFunctions.inc.php` corrected to deployeddave fork
- **FPP compatibility:** Added FPP 8.x, 9.x, and 10.x version blocks to `pluginInfo.json`
- **New projectors:** BenQ TK850/TK850i, W2700/HT3550, TK700STi
- **New projectors:** Epson ESC/VP21 Business and Home Theatre series
- **New projectors:** NEC/Sharp-NEC P627UL/P547UL, PE506UL/PE506WL, ME403U/ME423W/ME453X
- **New projectors:** ViewSonic PX701-4K, PX728-4K/PX748-4K
- **New projectors:** Optoma GT1080HDR, Optoma Laser Modern ZH/ZU/UHD series, Optoma EP7xx (from official RS232 spec PDF)
- **New projectors:** Panasonic PT-VMZ Series, PT-MZ Large Venue Series

### v2.1 (original FalconChristmas)
- FPP 8.x support
- PhpSerial.php replacement for php_serial.class.php

---

## License

GNU General Public License v2 — see LICENSE file.

## Credits

Original plugin by **Ben Shaver (bshaver)** and **Pat Delaney (patdelaney)**.  
Fork maintained by **deployeddave**.
