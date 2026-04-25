<?php
$DEBUG = false;
$skipJSsettings = 1;
include_once '/opt/fpp/www/common.php';
include_once 'functions.inc.php';
include_once 'commonFunctions.inc.php';
include 'projectorCommands.inc';
include_once 'version.inc';
$DEBUG = false;

// ── Connection status detection ──────────────────────────────────────────────
// Probe the saved device/IP at page load so we can show a real status widget.
$savedProtocol  = isset($pluginSettings['PROJ_PROTOCOL']) ? $pluginSettings['PROJ_PROTOCOL'] : 'SERIAL';
$savedDevice    = isset($pluginSettings['DEVICE'])        ? $pluginSettings['DEVICE']        : '';
$savedIP        = isset($pluginSettings['IP'])            ? $pluginSettings['IP']            : '';
$savedPort      = isset($pluginSettings['PORT'])          ? $pluginSettings['PORT']          : '';
$savedProjector = isset($pluginSettings['PROJECTOR'])     ? urldecode($pluginSettings['PROJECTOR']) : '';

$connStatus  = 'unknown';
$connMessage = '';

if ($savedProjector === '' || $savedProjector === '-- Select Projector --') {
    $connStatus  = 'unknown';
    $connMessage = 'No projector selected';

} elseif ($savedProtocol === 'SERIAL') {
    // For serial: check whether the /dev/ node exists on the Pi filesystem
    $devPath = '/dev/' . $savedDevice;
    if ($savedDevice === '') {
        $connStatus  = 'unknown';
        $connMessage = 'No serial device selected';
    } elseif (file_exists($devPath)) {
        $connStatus  = 'connected';
        $connMessage = 'Serial adapter detected at ' . htmlspecialchars($devPath);
    } else {
        $connStatus  = 'disconnected';
        $connMessage = 'Serial device not found: ' . htmlspecialchars($devPath);
    }

} elseif ($savedProtocol === 'PJLINK' || $savedProtocol === 'TCP') {
    // For network: attempt a 2-second TCP probe to the configured IP:port
    $probePort = ($savedPort !== '') ? (int)$savedPort : 4352;
    if ($savedIP === '') {
        $connStatus  = 'unknown';
        $connMessage = 'No IP address configured';
    } else {
        $socket = @fsockopen($savedIP, $probePort, $errno, $errstr, 2);
        if ($socket) {
            fclose($socket);
            $connStatus  = 'connected';
            $connMessage = 'Network reachable: '
                         . htmlspecialchars($savedIP) . ':' . $probePort;
        } else {
            $connStatus  = 'disconnected';
            $connMessage = 'Cannot reach ' . htmlspecialchars($savedIP) . ':' . $probePort
                         . ' (' . htmlspecialchars($errstr) . ')';
        }
    }
}

// Status colour map
$statusMap = [
    'connected'    => ['bg'=>'#0a2a1a','border'=>'#4ab87a','dot'=>'#4ab87a','label'=>'Connected'],
    'disconnected' => ['bg'=>'#2a0a0a','border'=>'#c94040','dot'=>'#c94040','label'=>'Not Detected'],
    'unknown'      => ['bg'=>'#1e1e2a','border'=>'#666',   'dot'=>'#888',   'label'=>'Unknown'],
];
$sc = $statusMap[$connStatus];
?>

<html>
<head></head>

<style>
@keyframes pcPulse {
    0%,100% { box-shadow: 0 0 4px <?=$sc['dot']?>; }
    50%      { box-shadow: 0 0 10px <?=$sc['dot']?>; }
}
</style>

<div id="projector" class="settings">
<legend>Projector Control</legend>

<?php /* ── Header row: version + help button ── */ ?>
<div style="display:flex; align-items:center; gap:16px; margin-bottom:14px;">
    <h2 style="margin:0;">Version <?echo $VERSION;?></h2>
    <a href="plugin.php?plugin=<?echo $pluginName ?>&page=help/plugin_setup.php"
       class="buttons btn btn-outline-info btn-sm"
       style="text-decoration:none; padding:4px 12px; font-size:13px;">
        &#x2753; Help
    </a>
</div>

<?php /* ── Connection status widget ── */ ?>
<div style="
        display:inline-flex; align-items:center; gap:10px;
        background:<?=$sc['bg']?>; border:1px solid <?=$sc['border']?>;
        border-radius:6px; padding:8px 16px; margin-bottom:18px;">
    <span style="
            width:12px; height:12px; border-radius:50%;
            background:<?=$sc['dot']?>; flex-shrink:0;
            <?php if ($connStatus === 'connected'): ?>
            animation: pcPulse 2s ease-in-out infinite;
            <?php endif; ?>"></span>
    <span style="font-size:13px; line-height:1.4;">
        <strong>Projector:</strong>
        <span style="color:<?=$sc['dot']?>; font-weight:600; margin:0 4px;">
            <?=$sc['label']?>
        </span>
        <span style="color:#888; font-size:12px;">
            &mdash; <?=htmlspecialchars($connMessage)?>
        </span>
    </span>
    <input type="button" class="buttons btn btn-sm"
           style="margin-left:6px; font-size:12px; padding:2px 10px;"
           value="&#x21bb; Refresh" onclick="location.reload();" />
</div>

<?php /* ── Instructions ── */ ?>
<div style="display:inline-block;">
<p style="display:inline;">Known Issues:
<ul>
<li>Does not support passwords on the projector</li>
</ul>
</p>
</div>
<div id="updatesAvailable" style="display:inline-block; vertical-align:top; margin-left:60px;"></div>
<p>Configuration:
<ul>
<li>Select your Projector — serial settings are loaded from the projector definition automatically</li>
<li>All serial settings are always visible so you can review and configure them whether or not the projector is currently connected</li>
<li>For network projectors, enter the IP address and port after selecting the projector</li>
<li>Click Save to apply all settings and generate the FPP Command scripts</li>
</ul>
<br>
</p>

<?php /* ── Plugin settings fields ── */ ?>
<div id="enabled">ENABLE PLUGIN <?PrintSettingCheckbox("Projector Control", "ENABLED",0, 0, "ON", "OFF", $pluginName);?></div></p>

<div id="proj">Projector: <? PrintSettingSelect("ProjectorType", "PROJECTOR", 1, 0, $defaultValue="-- Select Projector --", $values = getProjectors(), $pluginName, "projectorChanged"); ?></div></p>

<?php /*
    Serial fields are ALWAYS VISIBLE regardless of saved protocol or whether
    a projector is connected. Previously these were hidden by default and only
    revealed after a projector was selected and saved — making it impossible to
    review or configure serial settings without a live connection.

    For network projectors the serial fields will be hidden by updateVisibility()
    once the page loads with a saved TCP/PJLINK protocol, but they remain
    accessible as the default view for new installs.
*/ ?>
<div id="serial">Serial Device: <? PrintSettingSelect("Device", "DEVICE", 0, 0, "", $values = get_serialDevices(), $pluginName); ?></div></p>
<div id="baud">Baud Rate: <? PrintSettingSelect("BaudRate", "BAUD_RATE", 0, 0, "9600", $values = getBaudRates(), $pluginName); ?></div></p>
<div id="char">Char Bits: <? PrintSettingSelect("CharBits", "CHAR_BITS", 0, 0, "8", $values = getCharBits(), $pluginName); ?></div></p>
<div id="stop">Stop Bits: <? PrintSettingSelect("StopBits", "STOP_BITS", 0, 0, "1", array("1"=>"1","2"=>"2"), $pluginName); ?></div></p>
<div id="parity">Parity: <? PrintSettingSelect("Parity", "PARITY", 0, 0, $defaultValue="none", array("none"=>"none","even"=>"even","odd"=>"odd"), $pluginName); ?></div></p>

<div class="alert alert-warning" id="IP_Warning" style="color:Red; display:none">
<strong>Warning!</strong> This is an invalid IP
</div>
<div id="ip" style="display:none">Projector IP: <? PrintSettingTextSaved("IP", 0,0, 15, 15, $pluginName, "", "validateIP"); ?>
<input type="button" class="buttons" onClick='PingIP($("#IP").val(), 3);' value='Ping'>
</div></p>

<div id="pass" style="display:none">Projector Password: <? PrintSettingTextSaved("PROJ_PASSWORD", 0,0, 30, 30, $pluginName); ?></div></p>

<div class="alert alert-warning" id="Port_Warning" style="color:Red; display:none">
<strong>Warning!</strong> This is an invalid Port. Only numbers are valid
</div>
<div id="port" style="display:none">Port: <? PrintSettingTextSaved("PORT", 0,0, 6, 6, $pluginName, "", "validatePort"); ?></div></p>

<p>To report a bug, please file it against the Projector Control plug-in project on Git:
<a href="https://github.com/deployeddave/FPP-Plugin-Projector-Control/issues"> Projector Control Issues Link</a>
</p>

<script>
// Run visibility on load to handle network projectors correctly
updateVisibility();

function projectorChanged(){
    GetSync("plugin.php?plugin=<?echo $pluginName ?>&page=functions.inc.php&action=create_scripts&nopage=1");
    location.reload();
    updateVisibility();
}

function updateVisibility(){
    var protocol = "<?echo $PROJ_PROTOCOL?>";

    switch (protocol) {

        case "PJLINK":
            // Network only — hide all serial fields, show IP
            document.getElementById('ip').style.display     = "block";
            document.getElementById('pass').style.display   = "none";
            document.getElementById('serial').style.display = "none";
            document.getElementById('baud').style.display   = "none";
            document.getElementById('char').style.display   = "none";
            document.getElementById('stop').style.display   = "none";
            document.getElementById('parity').style.display = "none";
            document.getElementById('port').style.display   = "none";
            break;

        case "TCP":
            // Network only — hide all serial fields, show IP + port
            document.getElementById('ip').style.display     = "block";
            document.getElementById('pass').style.display   = "none";
            document.getElementById('serial').style.display = "none";
            document.getElementById('baud').style.display   = "none";
            document.getElementById('char').style.display   = "none";
            document.getElementById('stop').style.display   = "none";
            document.getElementById('parity').style.display = "none";
            document.getElementById('port').style.display   = "block";
            break;

        case "SERIAL":
        default:
            // Serial is the default for new installs and unknown protocol.
            // All serial fields visible so users can configure without
            // needing to connect the projector first.
            document.getElementById('ip').style.display     = "none";
            document.getElementById('pass').style.display   = "none";
            document.getElementById('serial').style.display = "block";
            document.getElementById('baud').style.display   = "block";
            document.getElementById('char').style.display   = "block";
            document.getElementById('stop').style.display   = "block";
            document.getElementById('parity').style.display = "block";
            document.getElementById('port').style.display   = "none";
            break;
    }
}

function UpgradePlugin(plugin) {
    var url = 'api/plugin/' + plugin + '/upgrade?stream=true';
    DisplayProgressDialog("pluginsProgressPopup", "Upgrade Plugin");
    StreamURL(url, 'pluginsProgressPopupText', 'PluginProgressDialogDone', 'PluginProgressDialogDone');
}
</script>

</html>
