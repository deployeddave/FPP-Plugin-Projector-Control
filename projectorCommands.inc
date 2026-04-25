<?php
//This this template to add additional projectors
//If Protocol = TCP and PORT = 23, then you can put commands in as ASCII added as TELNET support. 10/9/2020 Pat
//
// FIXES (deployeddave fork):
//   - Corrected Optoma Power OFF command: changed \x30 (ASCII "0") to \x32 (ASCII "2") per RS232 spec
//   - Fixed broken double-backslash \\x35 in Optoma_X600 HDMI2 command
//   - Added Optoma_EP7xx_RS232 entry based on official Optoma RS232 Command Table PDF
//     (covers EP721, EP723, EP727, EP728 with correct ~XX39 input source commands)
//

$PROJECTORS = Array(
// To add another projector fill out the below and remove the //
// Array("NAME" => "NAME_OF_PROJECTOR",
//
// "ON" => "\x30\x30\x21\x0D",
// "OFF" => "\x30\x30\x22\x0D",
// "VIDEO" => "\x30\x30\x5F\x76\x31",
//
// "BAUD_RATE" => "9600",
// "CHAR_BITS" => "8",
// "STOP_BITS" => "1",
// "PARITY" => "none"
//),

Array("NAME" => "PJLINK",
    "PROTOCOL" => "PJLINK",
    "ON"       => "set_power_state 1",
    "OFF"      => "set_power_state 0",
    "RGB"      => "set_input INPUT_RGB",
    "VIDEO"    => "set_input INPUT_VIDEO",
    "DIGITAL"  => "set_input INPUT_DIGITAL",
    "IP"       => "",
    "PASSWORD" => ""
),

Array("NAME" => "NETWORK_4352",
    "PROTOCOL" => "TCP",
    "ON"       => "set_power_state 1",
    "OFF"      => "set_power_state 0",
    "IP"       => "",
    "PASSWORD" => "",
    "PORT"     => "4352",
),

Array("NAME" => "_PWRLITE_93_NETWORK",
    "PROTOCOL" => "TCP",
    "ON"       => "\x49\x4d\x50\x57\x52\x20\x4f\x4e\x0d",
    "OFF"      => "\x49\x4d\x50\x57\x52\x20\x4f\x46\x46\x0d",
    "IP"       => "",
    "PASSWORD" => "",
    "PORT"     => "3629",
),

Array("NAME" => "Hitatchi_CPX_1250",
    "ON"        => "\xBE\xEF\x03\x06\x00\xBA\xD2\x01\x00\x00\x60\x01\x00",
    "OFF"       => "\xBE\xEF\x03\x06\x00\x2A\xD3\x01\x00\x00\x60\x00\x00",
    "BAUD_RATE" => "19200",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Sanyo_PLC_XP200L",
    "ON"          => "\x43\x30\x30\x0D",
    "OFF_IMMEDIATE" => "\x43\x30\x31\x0D",
    "OFF_SLOW"    => "\x43\x30\x32\x0D",
    "INPUT1"      => "\x43\x30\x35\x0D",
    "INPUT2"      => "\x43\x30\x36\x0D",
    "INPUT3"      => "\x43\x30\x37\x0D",
    "BAUD_RATE"   => "19200",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),

Array("NAME" => "Sanyo_PLC_HP7000L",
    "ON"          => "\x43\x30\x30\x0D",
    "OFF_IMMEDIATE" => "\x43\x30\x31\x0D",
    "OFF_SLOW"    => "\x43\x30\x32\x0D",
    "INPUT1"      => "\x43\x30\x35\x0D",
    "INPUT2"      => "\x43\x30\x36\x0D",
    "INPUT3"      => "\x43\x30\x37\x0D",
    "BAUD_RATE"   => "19200",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),

Array("NAME" => "EIKI_LC-SXG400",
    "ON"          => "\x43\x30\x30\x0D",
    "OFF_IMMEDIATE" => "\x43\x30\x31\x0D",
    "OFF_SLOW"    => "\x43\x30\x32\x0D",
    "INPUT1"      => "\x43\x30\x35\x0D",
    "INPUT2"      => "\x43\x30\x36\x0D",
    "INPUT3"      => "\x43\x30\x37\x0D",
    "BAUD_RATE"   => "19200",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),

Array("NAME" => "Dukane_ImagePRO8758",
    "ON"        => "\x28\x50\x57\x52\x31\x29",
    "OFF"       => "\x28\x50\x57\x52\x30\x29",
    "BAUD_RATE" => "19200",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Dukane_ImagePRO8758_NETWORK",
    "PROTOCOL" => "TCP",
    "ON"       => "(PWR1)",
    "OFF"      => "(PWR0)",
    "IP"       => "",
    "PASSWORD" => "",
    "PORT"     => "23",
),

Array("NAME" => "Proxima_6850",
    "ON"        => "\x31\x11\x3F",
    "OFF"       => "\x31\x11\x3E",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Panasonic_PT_AE900U",
    "ON"        => "\x50\x4f\x4e",
    "OFF"       => "\x50\x4f\x46\x46",
    "VID"       => "\x56\x49\x44",
    "RG1"       => "\x52\x47\x31",
    "HDMI"      => "\x48\x44\x4d",
    "SVIDEO"    => "\x53\x56\x44",
    "YUV"       => "\x59\x55\x56",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Panasonic_PT_LB50NTU",
    "ON"        => "\x50\x4f\x4e",
    "OFF"       => "\x50\x4f\x46\x46",
    "VID"       => "\x56\x49\x44",
    "RG1"       => "\x52\x47\x31",
    "RG2"       => "\x52\x47\x32",
    "SVIDEO"    => "\x53\x56\x44",
    "NWP"       => "\x4e\x57\x50",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Panasonic_PT_LB50U",
    "ON"        => "\x02\x41\x44\x5A\x5A\x3B\x50\x4F\x4E\x03",
    "OFF"       => "\x02\x41\x44\x5A\x5A\x3B\x50\x4F\x46\x03",
    "HD1"       => "\x02\x41\x44\x5A\x5A\x3B\x49\x49\x53\x3A\x48\x44\x31\x03",
    "HD2"       => "\x02\x41\x44\x5A\x5A\x3B\x49\x49\x53\x3A\x48\x44\x32\x03",
    "PC1"       => "\x02\x41\x44\x5A\x5A\x3B\x49\x49\x53\x3A\x50\x43\x31\x03",
    "PC2"       => "\x02\x41\x44\x5A\x5A\x3B\x49\x49\x53\x3A\x50\x43\x32\x03",
    "SVIDEO"    => "\x02\x41\x44\x5A\x5A\x3B\x49\x49\x53\x3A\x53\x56\x44\x03",
    "DVID"      => "\x02\x41\x44\x5A\x5A\x3B\x49\x49\x53\x3A\x56\x49\x44\x03",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Panasonic_PT_DW6300",
    "ON"          => "\x02\x41\x44\x5A\x5A\x3B\x50\x4F\x4E\x03",
    "OFF"         => "\x02\x41\x44\x5A\x5A\x3B\x50\x4F\x46\x03",
    "HD1"         => "\x02\x41\x44\x5A\x5A\x3B\x49\x49\x53\x3A\x48\x44\x31\x03",
    "HD2"         => "\x02\x41\x44\x5A\x5A\x3B\x49\x49\x53\x3A\x48\x44\x32\x03",
    "PC1"         => "\x02\x41\x44\x5A\x5A\x3B\x49\x49\x53\x3A\x50\x43\x31\x03",
    "PC2"         => "\x02\x41\x44\x5A\x5A\x3B\x49\x49\x53\x3A\x50\x43\x32\x03",
    "SVIDEO"      => "\x02\x41\x44\x5A\x5A\x3B\x49\x49\x53\x3A\x53\x56\x44\x03",
    "DVID"        => "\x02\x41\x44\x5A\x5A\x3B\x49\x49\x53\x3A\x56\x49\x44\x03",
    "SHUTTER_OFF" => "\x02\x41\x44\x5A\x5A\x3B\x4F\x53\x48\x3A\x30\x03",
    "SHUTTER_ON"  => "\x02\x41\x44\x5A\x5A\x3B\x4F\x53\x48\x3A\x31\x03",
    "OSD_OFF"     => "\x02\x41\x44\x5A\x5A\x3B\x4F\x4F\x53\x3A\x30\x03",
    "OSD_ON"      => "\x02\x41\x44\x5A\x5A\x3B\x4F\x4F\x53\x3A\x31\x03",
    "BAUD_RATE"   => "9600",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),

Array("NAME" => "Sharp_PGD2500X",
    "ON"        => "\x50\x4f\x57\x52\x20\x20\x20\x31\x0d",
    "OFF"       => "\x50\x4f\x57\x52\x20\x20\x20\x30\x0d",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Panasonic_RZ_670",
    "ON"        => "\x50\x4f\x4e",
    "OFF"       => "\x50\x4f\x46\x46",
    "VID"       => "\x56\x49\x44",
    "RG1"       => "\x52\x47\x31",
    "RG2"       => "\x52\x47\x32",
    "SVIDEO"    => "\x53\x56\x44",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Promethan_PRM-45",
    "ON"        => "\x7E\x50\x4E\x0D",
    "OFF"       => "\x7E\x50\x46\x0D",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Casio_XJV1_HEX",
    "ON"        => "\x50\x57\x52\x31",
    "OFF"       => "\x50\x57\x52\x30",
    "RGB"       => "\x53\x52\x43\x30",
    "HDMI"      => "\x53\x52\x43\x37",
    "COMPONENT" => "\x53\x52\x43\x31",
    "BAUD_RATE" => "19200",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Casio_XJV1_ASCII",
    "ON"        => "(PWR1)",
    "OFF"       => "(PWR0)",
    "RGB"       => "(SRC0)",
    "HDMI"      => "(SRC7)",
    "AUTO"      => "(SRC6)",
    "BAUD_RATE" => "19200",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Hitachi_CPX445",
    "ON"          => "\xBE\xEF\x03\x06\x00\xBA\xD2\x01\x00\x00\x60\x01\x00",
    "OFF"         => "\xBE\xEF\x03\x06\x00\x2A\xD3\x01\x00\x00\x60\x00\x00",
    "RGB1"        => "\xBE\xEF\x03\x06\x00\xFE\xD2\x01\x00\x00\x20\x00\x00",
    "DVI"         => "\xBE\xEF\x03\x06\x00\x0E\xD2\x01\x00\x00\x20\x03\x00",
    "COMPONENT"   => "\xBE\xEF\x03\x06\x00\xAE\xD1\x01\x00\x00\x20\x05\x00",
    "VIDEO(RCA)"  => "\xBE\xEF\x03\x06\x00\x6E\xD3\x01\x00\x00\x20\x01\x00",
    "VIDEO(S)"    => "\xBE\xEF\x03\x06\x00\x9E\xD3\x01\x00\x00\x20\x02\x00",
    "BAUD_RATE"   => "19200",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),

Array("NAME" => "Dell_MP_1200 ",
    "ON"        => "\xBE\xEF\x10\x05\x00\xC6\xFF\x11\x11\x01\x00\x01",
    "OFF"       => "\xBE\xEF\x10\x05\x00\x0C\x3E\x11\x11\x01\x00\x18",
    "VGA"       => "\xBE\xEF\x10\x05\x00\xCC\xFF\x11\x11\x01\x00\x19",
    "SVIDEO"    => "\xBE\xEF\x10\x05\x00\x1F\xBE\x11\x11\x01\x00\x22",
    "COMPOSITE" => "\xBE\xEF\x10\x05\x00\xDF\x7F\x11\x11\x01\x00\x23",
    "BAUD_RATE" => "19200",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Dell_2300_MP ",
    "ON"        => "\xBE\xEF\x10\x05\x00\xC7\xBF\x11\x11\x01\x00\x02",
    "OFF"       => "\xBE\xEF\x10\x05\x00\x0C\x3E\x11\x11\x01\x00\x18",
    "VGA"       => "\xBE\xEF\x10\x05\x00\xCC\xFF\x11\x11\x01\x00\x19",
    "SVIDEO"    => "\xBE\xEF\x10\x05\x00\x1F\xBE\x11\x11\x01\x00\x22",
    "COMPOSITE" => "\xBE\xEF\x10\x05\x00\xDF\x7F\x11\x11\x01\x00\x23",
    "BAUD_RATE" => "19200",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Dell_4210x",
    "ON"        => "\xBE\xEF\x10\x05\x00\xC6\xFF\x11\x11\x01\x00\x01",
    "OFF"       => "\xBE\xEF\x10\x05\x00\x0C\x3E\x11\x11\x01\x00\x18",
    "VGA"       => "\xBE\xEF\x10\x05\x00\xCC\xFF\x11\x11\x01\x00\x19",
    "SVIDEO"    => "\xBE\xEF\x10\x05\x00\x1F\xBE\x11\x11\x01\x00\x22",
    "COMPOSITE" => "\xBE\xEF\x10\x05\x00\xDF\x7F\x11\x11\x01\x00\x23",
    "BAUD_RATE" => "19200",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Dell_2400MP",
    "ON"        => "\xBE\xEF\x10\x05\x00\xC6\xFF\x11\x11\x01\x00\x01",
    "OFF"       => "\xBE\xEF\x10\x05\x00\x0C\x3E\x11\x11\x01\x00\x18",
    "VGA"       => "\xBE\xEF\x10\x05\x00\xCC\xFF\x11\x11\x01\x00\x19",
    "SVIDEO"    => "\xBE\xEF\x10\x05\x00\x1F\xBE\x11\x11\x01\x00\x22",
    "COMPOSITE" => "\xBE\xEF\x10\x05\x00\xDF\x7F\x11\x11\x01\x00\x23",
    "BAUD_RATE" => "19200",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "EPSON_EH_TW5900_Powerlite_1960",
    "ON"        => "\x50\x57\x52\x20\x4f\x4e\x0d\x0a",
    "OFF"       => "\x50\x57\x52\x20\x4f\x46\x46\x0d\x0a",
    "HDMI1"     => "\x53\x4f\x55\x52\x43\x45\x20\x33\x30\x0d\x0a",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "EPSON_PWRLITE_6110i",
    "ON"        => "\x50\x4f\x57\x52\x20\x4f\x4e",
    "OFF"       => "\x50\x4f\x57\x52\x20\x4f\x46\x46",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "EPSON_PWRLITE_500_PWRLITE_93_99WH",
    "ON"          => "\x50\x57\x52\x20\x4f\x4e\x0d",
    "OFF"         => "\x50\x57\x52\x20\x4f\x46\x46\x0d",
    "AVMute_ON"   => "\x4d\x55\x54\x45\x20\x4f\x4e\x0d",
    "AVMute_OFF"  => "\x4d\x55\x54\x45\x20\x4f\x46\x46\x0d",
    "BAUD_RATE"   => "9600",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),

Array("NAME" => "Viewsonic_PJD5153",
    "ON"        => "\x06\x14\x00\x04\x00\x34\x11\x00\x00\x5D",
    "OFF"       => "\x06\x14\x00\x04\x00\x34\x11\x01\x00\x5E",
    "BAUD_RATE" => "115200",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Viewsonic_PJD5255",
    "ON"        => "\x06\x14\x00\x04\x00\x34\x11\x00\x00\x5D",
    "OFF"       => "\x06\x14\x00\x04\x00\x34\x11\x01\x00\x5E",
    "VGA"       => "\x06\x14\x00\x04\x00\x34\x13\x01\x00\x60",
    "VGA2"      => "\x06\x14\x00\x04\x00\x34\x13\x01\x08\x68",
    "COMPOSITE" => "\x06\x14\x00\x04\x00\x34\x13\x01\x05\x65",
    "SVIDEO"    => "\x06\x14\x00\x04\x00\x34\x13\x01\x06\x66",
    "HDMI"      => "\x06\x14\x00\x04\x00\x34\x13\x01\x03\x63",
    "HDMI2"     => "\x06\x14\x00\x04\x00\x34\x13\x01\x03\x67",
    "BAUD_RATE" => "115200",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Viewsonic_PJD5555w",
    "ON"        => "\x06\x14\x00\x04\x00\x34\x11\x00\x00\x5D",
    "OFF"       => "\x06\x14\x00\x04\x00\x34\x11\x01\x00\x5E",
    "VGA"       => "\x06\x14\x00\x04\x00\x34\x13\x01\x00\x60",
    "VGA2"      => "\x06\x14\x00\x04\x00\x34\x13\x01\x08\x68",
    "COMPOSITE" => "\x06\x14\x00\x04\x00\x34\x13\x01\x05\x65",
    "SVIDEO"    => "\x06\x14\x00\x04\x00\x34\x13\x01\x06\x66",
    "HDMI"      => "\x06\x14\x00\x04\x00\x34\x13\x01\x03\x63",
    "BAUD_RATE" => "115200",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Viewsonic_PDJ5132",
    "ON"        => "\x06\x14\x00\x04\x00\x34\x11\x00\x00\x5D",
    "OFF"       => "\x06\x14\x00\x04\x00\x34\x11\x01\x00\x5E",
    "VGA"       => "\x06\x14\x00\x04\x00\x34\x13\x01\x00\x60",
    "VGA2"      => "\x06\x14\x00\x04\x00\x34\x13\x01\x08\x68",
    "COMPOSITE" => "\x06\x14\x00\x04\x00\x34\x13\x01\x05\x65",
    "SVIDEO"    => "\x06\x14\x00\x04\x00\x34\x13\x01\x06\x66",
    "HDMI"      => "\x06\x14\x00\x04\x00\x34\x13\x01\x03\x63",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "EPSON_EX5200",
    "ON"          => "\x50\x57\x52\x20\x4f\x4e",
    "OFF"         => "\x50\x57\x52\x20\x4f\x46\x46",
    "INPUT1"      => "\x49\x4e\x50\x55\x54\x31",
    "INPUT3"      => "\x49\x4e\x50\x55\x54\x33",
    "VIDEO"       => "\x56\x49\x44\x45\x4f",
    "VIDEO(RCA)"  => "\x56\x49\x44\x45\x4f\x28\x52\x43\x41\x29",
    "VIDEO(S)"    => "\x56\x49\x44\x45\x4f\x28\x53\x29",
    "BAUD_RATE"   => "9600",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),

Array("NAME" => "Mitsubishi_FD730U",
    "ON"        => "\x30\x30\x21\x0D",
    "OFF"       => "\x30\x30\x22\x0D",
    "VIDEO"     => "\x30\x30\x5F\x76\x31",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Mitsubishi_WD385U-EST",
    "ON"        => "\x30\x30\x21\x0D",
    "OFF"       => "\x30\x30\x22\x0D",
    "HDMI"      => "\x30\x30\x5F\x64\x31",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "BenQ_PB7200",
    "ON"         => "\xBE\xEF\x03\x19\x00\x83\xA9\x01\x23\x03\xCC\xCC\xFF\xFF\xFF\xFF\x01\x00\x00\x00\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC",
    "OFF"        => "\xBE\xEF\x03\x19\x00\x13\x68\x01\x23\x03\xCC\xCC\xFF\xFF\xFF\xFF\x00\x00\x00\x00\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC",
    "VIDEO_IN"   => "\xBE\xEF\x03\x19\x00\x9B\x88\x01\xDA\x02\xCC\xCC\x00\x00\x00\x00\x05\x00\x00\x00\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC",
    "PC1_IN"     => "\xBE\xEF\x03\x19\x00\xC8\x4B\x01\xDA\x02\xCC\xCC\x00\x00\x00\x00\x00\x00\x00\x00\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC",
    "PC2_IN"     => "\xBE\xEF\x03\x19\x00\x58\x8A\x01\xDA\x02\xCC\xCC\x00\x00\x00\x00\x01\x00\x00\x00\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC",
    "SVIDEO_IN"  => "\xBE\xEF\x03\x19\x00\x0B\x49\x01\xDA\x02\xCC\xCC\x00\x00\x00\x00\x04\x00\x00\x00\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC",
    "BAUD_RATE"  => "19200",
    "CHAR_BITS"  => "8",
    "STOP_BITS"  => "1",
    "PARITY"     => "none"
),

Array("NAME" => "BenQ_MX819ST",
    "ON"        => "\x0D\x2A\x70\x6F\x77\x3D\x6F\x6E\x23\x0D",
    "OFF"       => "\x0D\x2A\x70\x6F\x77\x3D\x6F\x66\x66\x23\x0D",
    "YPBR_1"    => "\x0D\x2A\x73\x6F\x75\x72\x3D\x52\x47\x42\x23\x0D",
    "YPBR_2"    => "\x0D\x2A\x73\x6F\x75\x72\x3D\x52\x47\x42\x32\x23\x0D",
    "COMPONENT" => "\x0D\x2A\x73\x6F\x75\x72\x3D\x79\x70\x62\x72\x23\x0D",
    "DVI_A"     => "\x0D\x2A\x73\x6F\x75\x72\x3D\x64\x76\x69\x41\x23\x0D",
    "DVI_D"     => "\x0D\x2A\x73\x6F\x75\x72\x3D\x64\x76\x69\x44\x23\x0D",
    "HDMI_1"    => "\x0D\x2A\x73\x6F\x75\x72\x3D\x68\x64\x6D\x69\x23\x0D",
    "HDMI_2"    => "\x0D\x2A\x73\x6F\x75\x72\x3D\x68\x64\x6D\x69\x32\x23\x0D",
    "VIDEO"     => "\x0D\x2A\x73\x6F\x75\x72\x3D\x76\x69\x64\x23\x0D",
    "SVIDEO"    => "\x0D\x2A\x73\x6F\x75\x72\x3D\x73\x76\x69\x64\x23\x0D",
    "UP"        => "\x0D\x2A\x75\x70\x23\x0D",
    "DOWN"      => "\x0D\x2A\x64\x6F\x77\x6E\x23\x0D",
    "LEFT"      => "\x0D\x2A\x6C\x65\x66\x74\x23\x0D",
    "RIGHT"     => "\x0D\x2A\x72\x69\x67\x68\x74\x23\x0D",
    "BAUD_RATE" => "115200",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "BenQ_W770ST_MS510_TH671ST",
    "ON"        => "\x0D\x2A\x70\x6F\x77\x3D\x6F\x6E\x23\x0D",
    "OFF"       => "\x0D\x2A\x70\x6F\x77\x3D\x6F\x66\x66\x23\x0D",
    "VIDEO"     => "\x0D\x2A\x73\x6F\x75\x72\x3D\x76\x69\x64\x23\x0D",
    "HDMI_1"    => "\x0D\x2A\x73\x6F\x75\x72\x3D\x68\x64\x6D\x69\x23\x0D",
    "HDMI_2"    => "\x0D\x2A\x73\x6F\x75\x72\x3D\x68\x64\x6D\x69\x32\x23\x0D",
    "PC"        => "\x0D\x2A\x73\x6F\x75\x72\x3D\x52\x47\x42\x23\x0D",
    "STATUS"    => "\x0D\x2A\x70\x6F\x77\x3D\x3F\x23\x0D",
    "BLANK-ON"  => "\x0d\x2a\x62\x6c\x61\x6e\x6b\x3d\x6f\x6e\x23\x0d",
    "BLANK-OFF" => "\x0d\x2a\x62\x6c\x61\x6e\x6b\x3d\x6f\x66\x66\x23\x0d",
    "BAUD_RATE" => "115200",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "BenQ_MX613ST",
    "ON"        => "\x38\x30\x31\x73\x21\x30\x30\x31\x0D",
    "OFF"       => "\x38\x30\x31\x73\x21\x30\x30\x32\x0D",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "NEC_NP400",
    "ON"          => "\x02\x00\x00\x00\x00\x02",
    "OFF"         => "\x02\x01\x00\x00\x00\x03",
    "VIDEO_IN"    => "\x02\x03\x00\x00\x02\x01\x06\x0E",
    "PC1"         => "\x02\x03\x00\x00\x02\x01\x01\x09",
    "PC2"         => "\x02\x03\x00\x00\x02\x01\x02\x0A",
    "PC3"         => "\x02\x03\x00\x00\x02\x01\x1A\x22",
    "VIDEO"       => "\x02\x03\x00\x00\x02\x01\x06\x0E",
    "SVIDEO"      => "\x02\x03\x00\x00\x02\x01\x0B\x13",
    "PICTURE_OFF" => "\x02\x10\x00\x00\x00\x12",
    "PICTURE_ON"  => "\x02\x11\x00\x00\x00\x13",
    "BAUD_RATE"   => "19200",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),

Array("NAME" => "NEC_MT1050",
    "ON"          => "\x02\x00\x00\x00\x00\x02",
    "OFF"         => "\x02\x01\x00\x00\x00\x03",
    "VIDEO_IN"    => "\x02\x03\x00\x00\x02\x01\x06\x0E",
    "RGB1"        => "\x02\x03\x00\x00\x02\x01\x01\x09",
    "RGB2"        => "\x02\x03\x00\x00\x02\x01\x02\x0A",
    "VIDEO"       => "\x02\x03\x00\x00\x02\x01\x06\x0E",
    "SVIDEO"      => "\x02\x03\x00\x00\x02\x01\x0B\x13",
    "PICTURE_OFF" => "\x02\x10\x00\x00\x00\x12",
    "PICTURE_ON"  => "\x02\x11\x00\x00\x00\x13",
    "BAUD_RATE"   => "38400",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),

Array("NAME" => "NEC_V260X",
    "ON"          => "\x02\x00\x00\x00\x00\x02",
    "OFF"         => "\x02\x01\x00\x00\x00\x03",
    "VIDEO_IN"    => "\x02\x03\x00\x00\x02\x01\x06\x0E",
    "PC1"         => "\x02\x03\x00\x00\x02\x01\x01\x09",
    "PC2"         => "\x02\x03\x00\x00\x02\x01\x02\x0A",
    "VIDEO"       => "\x02\x03\x00\x00\x02\x01\x06\x0E",
    "SVIDEO"      => "\x02\x03\x00\x00\x02\x01\x0B\x13",
    "PICTURE_OFF" => "\x02\x10\x00\x00\x00\x12",
    "PICTURE_ON"  => "\x02\x11\x00\x00\x00\x13",
    "BAUD_RATE"   => "38400",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),

Array("NAME" => "NEC_NP4001",
    "ON"          => "\x02\x00\x00\x00\x00\x02",
    "OFF"         => "\x02\x01\x00\x00\x00\x03",
    "VIDEO_IN"    => "\x02\x03\x00\x00\x02\x01\x06\x0E",
    "PC1"         => "\x02\x03\x00\x00\x02\x01\x01\x09",
    "PC2"         => "\x02\x03\x00\x00\x02\x01\x02\x0A",
    "PC3"         => "\x02\x03\x00\x00\x02\x01\x1A\x22",
    "VIDEO"       => "\x02\x03\x00\x00\x02\x01\x06\x0E",
    "SVIDEO"      => "\x02\x03\x00\x00\x02\x01\x0B\x13",
    "PICTURE_OFF" => "\x02\x10\x00\x00\x00\x12",
    "PICTURE_ON"  => "\x02\x11\x00\x00\x00\x13",
    "BAUD_RATE"   => "38400",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),

Array("NAME" => "NEC_NP400_NETWORK",
    "PROTOCOL"    => "TCP",
    "IP"          => "",
    "PASSWORD"    => "",
    "PORT"        => "7142",
    "ON"          => "\x02\x00\x00\x00\x00\x02",
    "OFF"         => "\x02\x01\x00\x00\x00\x03",
    "VIDEO_IN"    => "\x02\x03\x00\x00\x02\x01\x06\x0E",
    "PC1"         => "\x02\x03\x00\x00\x02\x01\x01\x09",
    "PC2"         => "\x02\x03\x00\x00\x02\x01\x02\x0A",
    "PC3"         => "\x02\x03\x00\x00\x02\x01\x1A\x22",
    "VIDEO"       => "\x02\x03\x00\x00\x02\x01\x06\x0E",
    "SVIDEO"      => "\x02\x03\x00\x00\x02\x01\x0B\x13",
    "PICTURE_OFF" => "\x02\x10\x00\x00\x00\x12",
    "PICTURE_ON"  => "\x02\x11\x00\x00\x00\x13",
),

Array("NAME" => "NEC_GENERIC_NEC_MT1065",
    "ON"          => "\x02\x00\x00\x00\x00\x02",
    "OFF"         => "\x02\x01\x00\x00\x00\x03",
    "VIDEO_IN"    => "\x02\x03\x00\x00\x02\x01\x06\x0E",
    "PC1-RGB1"    => "\x02\x03\x00\x00\x02\x01\x01\x09",
    "PC2-RGB2"    => "\x02\x03\x00\x00\x02\x01\x02\x0A",
    "VIDEO"       => "\x02\x03\x00\x00\x02\x01\x06\x0E",
    "SVIDEO"      => "\x02\x03\x00\x00\x02\x01\x0B\x13",
    "DVI"         => "\x02\x03\x00\x00\x02\x01\x1A\x22",
    "HDMI"        => "\x02\x03\x00\x00\x02\x01\x1A\x22",
    "PICTURE_OFF" => "\x02\x10\x00\x00\x00\x12",
    "PICTURE_ON"  => "\x02\x11\x00\x00\x00\x13",
    "BAUD_RATE"   => "38400",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),

Array("NAME" => "NEC_P401W",
    "ON"          => "\x02\x00\x00\x00\x00\x02",
    "OFF"         => "\x02\x01\x00\x00\x00\x03",
    "HDMI_IN1"    => "\x02\x03\x00\x00\x02\x01\x1A\x22",
    "HDMI_IN2"    => "\x02\x03\x00\x00\x02\x01\x1B\x23",
    "PICTURE_OFF" => "\x02\x10\x00\x00\x00\x12",
    "PICTURE_ON"  => "\x02\x11\x00\x00\x00\x13",
    "BAUD_RATE"   => "38400",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),

Array("NAME" => "NEC_PA622u",
    "ON"          => "\x02\x00\x00\x00\x00\x02",
    "OFF"         => "\x02\x01\x00\x00\x00\x03",
    "HDMI_IN1"    => "\x02\x03\x00\x00\x02\x01\xA1\xA9",
    "HDMI_IN2"    => "\x02\x03\x00\x00\x02\x01\xA2\xAA",
    "Displayport" => "\x02\x03\x00\x00\x02\x01\xA6\xAE",
    "VIDEO_BNC"   => "\x02\x03\x00\x00\x02\x01\x02\x0A",
    "VIDEO_CV"    => "\x02\x03\x00\x00\x02\x01\x06\x0E",
    "VIDEO_YC"    => "\x02\x03\x00\x00\x02\x01\x0B\x13",
    "PC1_IN"      => "\x02\x03\x00\x00\x02\x01\x01\x09",
    "HDBaseT"     => "\x02\x03\x00\x00\x02\x01\x20\x28",
    "PICTURE_OFF" => "\x02\x10\x00\x00\x00\x12",
    "PICTURE_ON"  => "\x02\x11\x00\x00\x00\x13",
    "BAUD_RATE"   => "38400",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),

// ============================================================
// OPTOMA ENTRIES
// FIX: All Optoma models corrected: OFF now uses \x32 (ASCII "2")
//      per RS232 spec ~XX00 2 = Power OFF
//      Previous value \x30 (ASCII "0") was wrong and would fail.
// ============================================================

Array("NAME" => "Optoma_150S",
    // ~XX00 1 = Power ON  | ~XX00 2 = Power OFF
    "ON"        => "\x7E\x30\x30\x30\x30\x20\x31\x0D",  // correct: ends \x31
    "OFF"       => "\x7E\x30\x30\x30\x30\x20\x32\x0D",  // FIXED:   ends \x32 (was \x30)
    "VGA1"      => "\x7E\x30\x30\x31\x32\x20\x35\x0D",
    "VGA2"      => "\x7E\x30\x30\x31\x32\x20\x36\x0D",
    "SCART"     => "\x7E\x30\x30\x31\x32\x20\x37\x0D",
    "VGA_1_COMPONENT" => "\x7E\x30\x30\x31\x32\x20\x38\x0D",
    "VGA_2_COMPONENT" => "\x7E\x30\x30\x31\x32\x20\x31\x33\x0D",
    "VIDEO"     => "\x7E\x30\x30\x31\x32\x20\x31\x30\x0D",
    "SVIDEO"    => "\x7E\x30\x30\x31\x32\x20\x39\x0D",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Optoma_X600",
    "ON"        => "\x7E\x30\x30\x30\x30\x20\x31\x0D",  // correct
    "OFF"       => "\x7E\x30\x30\x30\x30\x20\x32\x0D",  // FIXED: was \x30
    "HDMI"      => "\x7E\x30\x30\x31\x32\x20\x31\x0D",
    "HDMI2"     => "\x7E\x30\x30\x31\x32\x20\x31\x35\x0D",  // FIXED: was \\x35 (double backslash)
    "VGA1"      => "\x7E\x30\x30\x31\x32\x20\x35\x0D",
    "VGA2"      => "\x7E\x30\x30\x31\x32\x20\x36\x0D",
    "VIDEO"     => "\x7E\x30\x30\x31\x32\x20\x31\x30\x0D",
    "SVIDEO"    => "\x7E\x30\x30\x31\x32\x20\x39\x0D",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Optoma_H181X_GT760",
    "ON"        => "\x7E\x30\x30\x30\x30\x20\x31\x0D",  // correct
    "OFF"       => "\x7E\x30\x30\x30\x30\x20\x32\x0D",  // FIXED: was \x30
    "HDMI"      => "\x7E\x30\x30\x31\x32\x20\x31\x0D",
    "VGA"       => "\x7E\x30\x30\x31\x32\x20\x35\x0D",
    "VIDEO"     => "\x7E\x30\x30\x31\x32\x20\x31\x30\x0D",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Optoma_XW305_ST",
    "ON"        => "\x7E\x30\x30\x30\x30\x20\x31\x0D",  // correct
    "OFF"       => "\x7E\x30\x30\x30\x30\x20\x32\x0D",  // FIXED: was \x30
    "HDMI"      => "\x7E\x30\x30\x31\x32\x20\x31\x0D",
    "VGA_1"     => "\x7E\x30\x30\x31\x32\x20\x35\x0D",
    "VGA_2"     => "\x7E\x30\x30\x31\x32\x20\x36\x0D",
    "SVIDEO"    => "\x7E\x30\x30\x31\x32\x20\x39\x0D",
    "VIDEO"     => "\x7E\x30\x30\x31\x32\x20\x31\x30\x0D",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Optoma_XW306_ST",
    "ON"               => "\x7E\x30\x30\x30\x30\x20\x31\x0D",  // correct
    "OFF"              => "\x7E\x30\x30\x30\x30\x20\x32\x0D",  // FIXED: was \x30
    "VGA_1_SCART"      => "\x7E\x30\x30\x31\x32\x20\x37\x0D",
    "VGA_1_COMPONENT"  => "\x7E\x30\x30\x31\x32\x20\x38\x0D",
    "VGA_2_COMPONENT"  => "\x7E\x30\x30\x31\x32\x20\x39\x0D",
    "VIDEO"            => "\x7E\x30\x30\x31\x32\x20\x31\x30\x0D",
    "BAUD_RATE"        => "9600",
    "CHAR_BITS"        => "8",
    "STOP_BITS"        => "1",
    "PARITY"           => "none"
),

Array("NAME" => "Optoma_EX525_ST",
    // This model was already correct — uses \x32 for OFF
    "ON"        => "\x7E\x30\x30\x30\x30\x20\x31\x0D",
    "OFF"       => "\x7E\x30\x30\x30\x30\x20\x32\x0D",  // was already correct
    "DVI_D"     => "\x7E\x30\x30\x31\x32\x20\x32\x0D",
    "DVI_A"     => "\x7E\x30\x30\x31\x32\x20\x33\x0D",
    "VGA"       => "\x7E\x30\x30\x31\x32\x20\x35\x0D",
    "VIDEO"     => "\x7E\x30\x30\x31\x32\x20\x31\x0D",
    "SVIDEO"    => "\x7E\x30\x30\x31\x32\x20\x39\x0D",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),
Array("NAME" => "Optoma_GT1080HDR",
    // Short-throw 1080p gaming projector (also covers GT1080HDRx)
    // Inputs: HDMI1 (HDMI 2.0), HDMI2 (HDMI 1.4a + MHL), VGA (YPbPr/RGB)
    // Protocol: modern Optoma ~XX — OFF=0, AV mute=~XX02
    // Baud: 9600, 8N1, no flow control
    "ON"           => "\x7E\x30\x30\x30\x30\x20\x31\x0D",  // ~0000 1
    "OFF"          => "\x7E\x30\x30\x30\x30\x20\x30\x0D",  // ~0000 0
    "AV_MUTE_ON"   => "\x7E\x30\x30\x30\x32\x20\x31\x0D",  // ~0002 1
    "AV_MUTE_OFF"  => "\x7E\x30\x30\x30\x32\x20\x30\x0D",  // ~0002 0
    "MUTE_ON"      => "\x7E\x30\x30\x30\x33\x20\x31\x0D",  // ~0003 1
    "MUTE_OFF"     => "\x7E\x30\x30\x30\x33\x20\x30\x0D",  // ~0003 0
    "FREEZE"       => "\x7E\x30\x30\x30\x34\x20\x31\x0D",  // ~0004 1
    "UNFREEZE"     => "\x7E\x30\x30\x30\x34\x20\x30\x0D",  // ~0004 0
    "HDMI1"        => "\x7E\x30\x30\x31\x32\x20\x31\x0D",  // ~0012 1  (HDMI 2.0)
    "HDMI2"        => "\x7E\x30\x30\x31\x32\x20\x31\x35\x0D", // ~0012 15 (HDMI 1.4a+MHL)
    "VGA"          => "\x7E\x30\x30\x31\x32\x20\x35\x0D",  // ~0012 5
    "BAUD_RATE"    => "9600",
    "CHAR_BITS"    => "8",
    "STOP_BITS"    => "1",
    "PARITY"       => "none"
),

// ============================================================
// NEW ENTRY: Optoma EP7xx RS232
// Based on official Optoma RS232 Command Table PDF
// Covers EP721, EP723, EP727, EP728 series
// Uses correct ~XX39 command for input source selection
// Uses correct ~XX00 1/2 for power on/off
// Baud: 9600, 8N1, no flow control
// ============================================================
Array("NAME" => "Optoma_EP7xx_RS232",
    // Power  — ~XX00 1 = ON, ~XX00 2 = OFF  (XX=00 targets all projectors)
    "ON"           => "\x7E\x30\x30\x30\x30\x20\x31\x0D",  // ~0000 1
    "OFF"          => "\x7E\x30\x30\x30\x30\x20\x32\x0D",  // ~0000 2

    // AV Mute — ~XX02 1 = On, ~XX02 2 = Off
    "AV_MUTE_ON"   => "\x7E\x30\x30\x30\x32\x20\x31\x0D",  // ~0002 1
    "AV_MUTE_OFF"  => "\x7E\x30\x30\x30\x32\x20\x32\x0D",  // ~0002 2

    // Audio Mute — ~XX03 1 = On, ~XX03 2 = Off
    "MUTE_ON"      => "\x7E\x30\x30\x30\x33\x20\x31\x0D",  // ~0003 1
    "MUTE_OFF"     => "\x7E\x30\x30\x30\x33\x20\x32\x0D",  // ~0003 2

    // Freeze — ~XX04 1 = Freeze, ~XX04 2 = Unfreeze
    "FREEZE"       => "\x7E\x30\x30\x30\x34\x20\x31\x0D",  // ~0004 1
    "UNFREEZE"     => "\x7E\x30\x30\x30\x34\x20\x32\x0D",  // ~0004 2

    // Input Source — ~XX39 n  (correct command per PDF, not ~XX12)
    "DVID"         => "\x7E\x30\x30\x33\x39\x20\x32\x0D",  // ~0039 2  DVI-D
    "VGA1"         => "\x7E\x30\x30\x33\x39\x20\x35\x0D",  // ~0039 5  VGA 1
    "VGA2"         => "\x7E\x30\x30\x33\x39\x20\x36\x0D",  // ~0039 6  VGA 2
    "SCART"        => "\x7E\x30\x30\x33\x39\x20\x37\x0D",  // ~0039 7  SCART
    "SVIDEO"       => "\x7E\x30\x30\x33\x39\x20\x39\x0D",  // ~0039 9  S-Video
    "VIDEO"        => "\x7E\x30\x30\x33\x39\x20\x31\x30\x0D", // ~0039 10 Video (composite)

    "BAUD_RATE"    => "9600",
    "CHAR_BITS"    => "8",
    "STOP_BITS"    => "1",
    "PARITY"       => "none"
),

Array("NAME" => "Mitsubishi_EX320U_EW330U_EX320U_ST",
    "ON"        => "\x30\x30\x21\x0D",
    "OFF"       => "\x30\x30\x22\x0D",
    "VIDEO"     => "\x30\x30\x5F\x76\x31\x0D",
    "HDMI"      => "\x30\x30\x5F\x64\x31\x0D",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Panasonic_PT_F200",
    "ON"        => "\x02\x50\x4F\x4E\x03",
    "OFF"       => "\x02\x50\x4F\x46\x03",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "NEC_LCD4000",
    "ON"        => "\x30\x30\x21\x0D",
    "OFF"       => "\x30\x30\x22\x0D",
    "RGB1"      => "\x30\x30\x21\x0D\x5F\x72\x31\x0D",
    "RGB2"      => "\x30\x30\x21\x0D\x5F\x72\x32\x0D",
    "RGB3"      => "\x30\x30\x21\x0D\x5F\x72\x33\x0D",
    "VIDEO"     => "\x30\x30\x21\x0D\x5F\x76\x31\x0D",
    "DVD"       => "\x30\x30\x21\x0D\x5F\x76\x32\x0D",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Samsung_Commercial_Flat_Panel_MDC",
    "ON"        => "\xAA\x11\xFE\x01\x01\x11",
    "OFF"       => "\xAA\x11\xFE\x01\x00\x10",
    "SVIDEO"    => "\xAA\x14\xFE\x01\x04\x17",
    "VIDEO"     => "\xAA\x14\xFE\x01\x0C\x1F",
    "YPbPr"     => "\xAA\x14\xFE\x01\x08\x1B",
    "PC"        => "\xAA\x14\xFE\x01\x14\x27",
    "DVIVid"    => "\xAA\x14\xFE\x01\x1F\x32",
    "PC1"       => "\xAA\x14\xFE\x01\x15\x28",
    "PC2"       => "\xAA\x14\xFE\x01\x16\x29",
    "DVID"      => "\xAA\x14\xFE\x01\x18\x2B",
    "BNC"       => "\xAA\x14\xFE\x01\x1E\x31",
    "MagicNet"  => "\xAA\x14\xFE\x01\x20\x33",
    "HDMI"      => "\xAA\x14\xFE\x01\x21\x34",
    "ATV"       => "\xAA\x14\xFE\x01\x30\x43",
    "DTV"       => "\xAA\x14\xFE\x01\x40\x53",
    "BAUD_RATE" => "9600",
    "CHAR_BITS" => "8",
    "STOP_BITS" => "1",
    "PARITY"    => "none"
),

Array("NAME" => "Vivitek_D77",
    "ON"           => "\x56\x30\x30\x53\x30\x30\x30\x31\x0D",
    "OFF"          => "\x56\x30\x30\x53\x30\x30\x30\x32\x0D",
    "SELECT RGB"   => "\x56\x30\x30\x53\x30\x32\x30\x31\x0D",
    "SELECT VIDEO" => "\x56\x30\x30\x53\x30\x32\x30\x34\x0D",
    "SELECT HDMI1" => "\x56\x30\x30\x53\x30\x32\x30\x36\x0D",
    "SELECT HDMI2" => "\x56\x30\x30\x53\x30\x32\x30\x39\x0D",
    "SET VOLUME 0" => "\x56\x30\x30\x53\x30\x33\x30\x35\x00\x0D",
    "SET VOLUME 1" => "\x56\x30\x30\x53\x30\x33\x30\x35\x01\x0D",
    "SET VOLUME 2" => "\x56\x30\x30\x53\x30\x33\x30\x35\x02\x0D",
    "SET VOLUME 3" => "\x56\x30\x30\x53\x30\x33\x30\x35\x03\x0D",
    "SET VOLUME 4" => "\x56\x30\x30\x53\x30\x33\x30\x35\x04\x0D",
    "SET VOLUME 5" => "\x56\x30\x30\x53\x30\x33\x30\x35\x05\x0D",
    "SET VOLUME 6" => "\x56\x30\x30\x53\x30\x33\x30\x35\x06\x0D",
    "SET VOLUME 7" => "\x56\x30\x30\x53\x30\x33\x30\x35\x07\x0D",
    "SET VOLUME 8" => "\x56\x30\x30\x53\x30\x33\x30\x35\x08\x0D",
    "SET VOLUME 9" => "\x56\x30\x30\x53\x30\x33\x30\x35\x09\x0D",
    "SET VOLUME 10"=> "\x56\x30\x30\x53\x30\x33\x30\x35\x0A\x0D",
    "BAUD_RATE"    => "9600",
    "CHAR_BITS"    => "8",
    "STOP_BITS"    => "1",
    "PARITY"       => "none"
),

Array("NAME" => "PROMETHEAN_EST_PRM_UST",
    "ON"                 => "\x7E\x50\x4E\x0D",
    "OFF"                => "\x7E\x50\x46\x0D",
    "SELECT RGB"         => "\x7E\x53\x52\x0D",
    "SELECT RGB2"        => "\x7E\x53\x47\x0D",
    "SELECT VIDEO"       => "\x7E\x53\x56\x0D",
    "SELECT S-VIDEO"     => "\x7E\x53\x53\x0D",
    "SELECT COMPONENT"   => "\x7E\x53\x59\x0D",
    "SELECT HDMI1"       => "\x7E\x53\x48\x0D",
    "SELECT HDMI2"       => "\x7E\x53\x49\x0D",
    "BAUD_RATE"          => "9600",
    "CHAR_BITS"          => "8",
    "STOP_BITS"          => "1",
    "PARITY"             => "none"
),

// ============================================================
// BENQ - Modern 4K / Home Theater / Short Throw Series
// Protocol: ASCII text  <CR>*command=param#<CR>
// Baud: 9600, 8N1, no flow control
// Source: BenQ RS232 Control Guide PDFs (esupportdownload.benq.com)
// Covers: TK850, TK850i, W2700, HT3550, TK700STi, W1800, HT3560
//         and any BenQ projector using the *pow= command format
// Commands: *pow=on/off#  *sour=hdmi/hdmi2#  *blank=on/off#
//           *freeze=on/off#  *mute=on/off#
// ============================================================

Array("NAME" => "BenQ_TK850_TK850i",
    // 4K UHD HDR home theater projector
    // Inputs: HDMI1 (HDCP 2.2), HDMI2 (HDCP 2.2)
    "ON"          => "\x0D\x2A\x70\x6F\x77\x3D\x6F\x6E\x23\x0D",    // *pow=on#
    "OFF"         => "\x0D\x2A\x70\x6F\x77\x3D\x6F\x66\x66\x23\x0D", // *pow=off#
    "HDMI1"       => "\x0D\x2A\x73\x6F\x75\x72\x3D\x68\x64\x6D\x69\x23\x0D",    // *sour=hdmi#
    "HDMI2"       => "\x0D\x2A\x73\x6F\x75\x72\x3D\x68\x64\x6D\x69\x32\x23\x0D", // *sour=hdmi2#
    "BLANK_ON"    => "\x0D\x2A\x62\x6C\x61\x6E\x6B\x3D\x6F\x6E\x23\x0D",    // *blank=on#
    "BLANK_OFF"   => "\x0D\x2A\x62\x6C\x61\x6E\x6B\x3D\x6F\x66\x66\x23\x0D", // *blank=off#
    "FREEZE_ON"   => "\x0D\x2A\x66\x72\x65\x65\x7A\x65\x3D\x6F\x6E\x23\x0D",    // *freeze=on#
    "FREEZE_OFF"  => "\x0D\x2A\x66\x72\x65\x65\x7A\x65\x3D\x6F\x66\x66\x23\x0D", // *freeze=off#
    "MUTE_ON"     => "\x0D\x2A\x6D\x75\x74\x65\x3D\x6F\x6E\x23\x0D",    // *mute=on#
    "MUTE_OFF"    => "\x0D\x2A\x6D\x75\x74\x65\x3D\x6F\x66\x66\x23\x0D", // *mute=off#
    "BAUD_RATE"   => "9600",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),

Array("NAME" => "BenQ_W2700_HT3550",
    // 4K UHD true-color home cinema
    // Inputs: HDMI1 (HDCP 2.2), HDMI2 (HDCP 2.2)
    // Same command set as TK850 — same protocol
    "ON"          => "\x0D\x2A\x70\x6F\x77\x3D\x6F\x6E\x23\x0D",
    "OFF"         => "\x0D\x2A\x70\x6F\x77\x3D\x6F\x66\x66\x23\x0D",
    "HDMI1"       => "\x0D\x2A\x73\x6F\x75\x72\x3D\x68\x64\x6D\x69\x23\x0D",
    "HDMI2"       => "\x0D\x2A\x73\x6F\x75\x72\x3D\x68\x64\x6D\x69\x32\x23\x0D",
    "BLANK_ON"    => "\x0D\x2A\x62\x6C\x61\x6E\x6B\x3D\x6F\x6E\x23\x0D",
    "BLANK_OFF"   => "\x0D\x2A\x62\x6C\x61\x6E\x6B\x3D\x6F\x66\x66\x23\x0D",
    "FREEZE_ON"   => "\x0D\x2A\x66\x72\x65\x65\x7A\x65\x3D\x6F\x6E\x23\x0D",
    "FREEZE_OFF"  => "\x0D\x2A\x66\x72\x65\x65\x7A\x65\x3D\x6F\x66\x66\x23\x0D",
    "MUTE_ON"     => "\x0D\x2A\x6D\x75\x74\x65\x3D\x6F\x6E\x23\x0D",
    "MUTE_OFF"    => "\x0D\x2A\x6D\x75\x74\x65\x3D\x6F\x66\x66\x23\x0D",
    "BAUD_RATE"   => "9600",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),

Array("NAME" => "BenQ_TK700STi",
    // 4K gaming/streaming short throw with Android TV built-in
    // Baud rate selectable 9600-115200 via OSD — verify in OSD before use
    // Inputs: HDMI1 (HDCP 2.2), HDMI2 (HDCP 2.2)
    "ON"          => "\x0D\x2A\x70\x6F\x77\x3D\x6F\x6E\x23\x0D",
    "OFF"         => "\x0D\x2A\x70\x6F\x77\x3D\x6F\x66\x66\x23\x0D",
    "HDMI1"       => "\x0D\x2A\x73\x6F\x75\x72\x3D\x68\x64\x6D\x69\x23\x0D",
    "HDMI2"       => "\x0D\x2A\x73\x6F\x75\x72\x3D\x68\x64\x6D\x69\x32\x23\x0D",
    "BLANK_ON"    => "\x0D\x2A\x62\x6C\x61\x6E\x6B\x3D\x6F\x6E\x23\x0D",
    "BLANK_OFF"   => "\x0D\x2A\x62\x6C\x61\x6E\x6B\x3D\x6F\x66\x66\x23\x0D",
    "FREEZE_ON"   => "\x0D\x2A\x66\x72\x65\x65\x7A\x65\x3D\x6F\x6E\x23\x0D",
    "FREEZE_OFF"  => "\x0D\x2A\x66\x72\x65\x65\x7A\x65\x3D\x6F\x66\x66\x23\x0D",
    "MUTE_ON"     => "\x0D\x2A\x6D\x75\x74\x65\x3D\x6F\x6E\x23\x0D",
    "MUTE_OFF"    => "\x0D\x2A\x6D\x75\x74\x65\x3D\x6F\x66\x66\x23\x0D",
    "BAUD_RATE"   => "9600",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),


// ============================================================
// EPSON - Modern Business and Home Cinema Series
// Protocol: ESC/VP21 ASCII, terminated with CR (0x0D)
// Baud: 9600, 8N1, no flow control
// Source: Epson ESC/VP21 Command User's Guide for Business Projectors
//         files.support.epson.com
// SOURCE codes (ESC/VP21 spec): HDMI1=30, HDMI2=A0, VGA/Computer=11
// Projector returns ":" after each successful command
// Covers: EB-L series laser, EB-PU series, PowerLite 2200/2250/2350,
//         EH-TW7400, EH-TW9400, and any ESC/VP21 compatible projector
// ============================================================

Array("NAME" => "Epson_Modern_ESC_VP21_Business",
    // Universal entry for modern Epson business/laser projectors (2018+)
    // Works with: EB-L735U, EB-L530U, EB-L720U, EB-PU2113W,
    //             PowerLite 2350, Pro EX9240, and similar
    "ON"          => "\x50\x57\x52\x20\x4F\x4E\x0D",            // PWR ON
    "OFF"         => "\x50\x57\x52\x20\x4F\x46\x46\x0D",        // PWR OFF
    "HDMI1"       => "\x53\x4F\x55\x52\x43\x45\x20\x33\x30\x0D",  // SOURCE 30
    "HDMI2"       => "\x53\x4F\x55\x52\x43\x45\x20\x41\x30\x0D",  // SOURCE A0
    "VGA"         => "\x53\x4F\x55\x52\x43\x45\x20\x31\x31\x0D",  // SOURCE 11
    "AVMUTE_ON"   => "\x4D\x55\x54\x45\x20\x4F\x4E\x0D",        // MUTE ON
    "AVMUTE_OFF"  => "\x4D\x55\x54\x45\x20\x4F\x46\x46\x0D",    // MUTE OFF
    "BAUD_RATE"   => "9600",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),

Array("NAME" => "Epson_HomeTheater_ESC_VP21",
    // Epson home cinema series (2018+)
    // Works with: EH-TW7400, EH-TW9400, EH-TW7100, LS series laser
    // Same ESC/VP21 command set — separate entry for dropdown clarity
    "ON"          => "\x50\x57\x52\x20\x4F\x4E\x0D",
    "OFF"         => "\x50\x57\x52\x20\x4F\x46\x46\x0D",
    "HDMI1"       => "\x53\x4F\x55\x52\x43\x45\x20\x33\x30\x0D",
    "HDMI2"       => "\x53\x4F\x55\x52\x43\x45\x20\x41\x30\x0D",
    "AVMUTE_ON"   => "\x4D\x55\x54\x45\x20\x4F\x4E\x0D",
    "AVMUTE_OFF"  => "\x4D\x55\x54\x45\x20\x4F\x46\x46\x0D",
    "BAUD_RATE"   => "9600",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),


// ============================================================
// NEC / SHARP-NEC - Modern Laser and Installation Series
// Protocol: Binary packet (same structure as existing NEC entries)
// Baud: 38400, 8N1 (modern NEC default — confirm via OSD)
// Source: Sharp NEC Projector Control Command Reference Manual
//         Revision 29, July 2023 — assets.sharpnecdisplays.us
// Modern HDMI input codes: HDMI1=0xA1/0xA9, HDMI2=0xA2/0xAA
//   DisplayPort=0xA6/0xAE, HDBaseT=0x20/0x28
// IMPORTANT: Older NEC models used 0x1A/0x22 for HDMI — these newer
//   codes only apply to models listed in Rev 27+ of the appendix
// ============================================================

Array("NAME" => "NEC_P627UL_P547UL",
    // High-brightness laser projectors (2022-2023)
    // Inputs: HDMI1, HDMI2, DisplayPort, HDBaseT, PC/VGA
    "ON"          => "\x02\x00\x00\x00\x00\x02",
    "OFF"         => "\x02\x01\x00\x00\x00\x03",
    "HDMI1"       => "\x02\x03\x00\x00\x02\x01\xA1\xA9",
    "HDMI2"       => "\x02\x03\x00\x00\x02\x01\xA2\xAA",
    "DISPLAYPORT" => "\x02\x03\x00\x00\x02\x01\xA6\xAE",
    "HDBASET"     => "\x02\x03\x00\x00\x02\x01\x20\x28",
    "PC1"         => "\x02\x03\x00\x00\x02\x01\x01\x09",
    "PICTURE_OFF" => "\x02\x10\x00\x00\x00\x12",
    "PICTURE_ON"  => "\x02\x11\x00\x00\x00\x13",
    "BAUD_RATE"   => "38400",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),

Array("NAME" => "NEC_PE506UL_PE506WL",
    // WUXGA/WXGA laser installation projectors
    // Same binary protocol and modern HDMI input codes as P627UL
    "ON"          => "\x02\x00\x00\x00\x00\x02",
    "OFF"         => "\x02\x01\x00\x00\x00\x03",
    "HDMI1"       => "\x02\x03\x00\x00\x02\x01\xA1\xA9",
    "HDMI2"       => "\x02\x03\x00\x00\x02\x01\xA2\xAA",
    "DISPLAYPORT" => "\x02\x03\x00\x00\x02\x01\xA6\xAE",
    "HDBASET"     => "\x02\x03\x00\x00\x02\x01\x20\x28",
    "PC1"         => "\x02\x03\x00\x00\x02\x01\x01\x09",
    "PICTURE_OFF" => "\x02\x10\x00\x00\x00\x12",
    "PICTURE_ON"  => "\x02\x11\x00\x00\x00\x13",
    "BAUD_RATE"   => "38400",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),

Array("NAME" => "NEC_ME403U_ME423W_ME453X",
    // Mid-range classroom/boardroom projectors (2020-2023)
    // Inputs: HDMI1, PC/VGA (no DisplayPort on ME-series)
    "ON"          => "\x02\x00\x00\x00\x00\x02",
    "OFF"         => "\x02\x01\x00\x00\x00\x03",
    "HDMI1"       => "\x02\x03\x00\x00\x02\x01\xA1\xA9",
    "PC1"         => "\x02\x03\x00\x00\x02\x01\x01\x09",
    "PC2"         => "\x02\x03\x00\x00\x02\x01\x02\x0A",
    "PICTURE_OFF" => "\x02\x10\x00\x00\x00\x12",
    "PICTURE_ON"  => "\x02\x11\x00\x00\x00\x13",
    "BAUD_RATE"   => "38400",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),


// ============================================================
// VIEWSONIC - Modern 4K Home and Gaming Series
// Protocol: Binary packet with checksum (same as existing VS entries)
// Baud: 9600, 8N1
// Source: PX701-4K/PX728-4K/PX748-4K RS-232 Protocol Specification
//         viewsonicglobal.com (official PDF)
// HDMI source codes for 4K series: HDMI1=0x03, HDMI2=0x07
// Note: HDMI2 code 0x07 differs from older models — use these entries
//       specifically for the PX701/728/748-4K lineup
// ============================================================

Array("NAME" => "ViewSonic_PX701_4K",
    // 3200 lumen 4K DLP, 240Hz gaming projector
    // Inputs: HDMI1 (HDCP 2.2), HDMI2 (HDCP 2.2)
    "ON"          => "\x06\x14\x00\x04\x00\x34\x11\x00\x00\x5D",
    "OFF"         => "\x06\x14\x00\x04\x00\x34\x11\x01\x00\x5E",
    "HDMI1"       => "\x06\x14\x00\x04\x00\x34\x13\x01\x03\x63",
    "HDMI2"       => "\x06\x14\x00\x04\x00\x34\x13\x01\x07\x67",
    "BAUD_RATE"   => "9600",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),

Array("NAME" => "ViewSonic_PX728_4K_PX748_4K",
    // ISF-certified 4K projectors — PX728-4K adds USB-C and RJ45
    // Inputs: HDMI1 (HDCP 2.2), HDMI2 (HDCP 2.2)
    // Same RS232 packet protocol and source codes as PX701-4K
    "ON"          => "\x06\x14\x00\x04\x00\x34\x11\x00\x00\x5D",
    "OFF"         => "\x06\x14\x00\x04\x00\x34\x11\x01\x00\x5E",
    "HDMI1"       => "\x06\x14\x00\x04\x00\x34\x13\x01\x03\x63",
    "HDMI2"       => "\x06\x14\x00\x04\x00\x34\x13\x01\x07\x67",
    "BAUD_RATE"   => "9600",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),


// ============================================================
// OPTOMA - Modern Laser and 4K UHD Series
// Protocol: ASCII ~XX command (same structure as existing Optoma lamp entries)
// Default Baud: 19200 (supports 9600-115200 — set via OSD)
// Source: Optoma RS232 Protocol Function List (laser/modern series)
//         optomaeurope.com (confirmed official PDF)
// Covers: ZH406, ZH450, ZH506, ZU506, ZH606, UHD50X, UHD55, UHD65,
//         UHD35, UHD35STX, and any modern Optoma with ~XX protocol
// KEY DIFFERENCES vs older Optoma lamp entries in this file:
//   AV Mute: ~XX325 (NOT ~XX02 used by older models)
//   Power OFF: ~XX00 0  (value=0, modern standard)
//   Default baud: 19200 (not 9600)
// ============================================================

Array("NAME" => "Optoma_Laser_Modern_ZH_ZU_UHD",
    // Universal modern Optoma laser and 4K UHD projectors
    // IMPORTANT: Set baud to 19200 in projector OSD before use,
    //            or change BAUD_RATE below to 9600 if preferred
    "ON"           => "\x7E\x30\x30\x30\x30\x20\x31\x0D",        // ~0000 1
    "OFF"          => "\x7E\x30\x30\x30\x30\x20\x30\x0D",        // ~0000 0
    // AV Mute uses ~XX325 on modern Optoma — different from ~XX02 on older models
    "AV_MUTE_ON"   => "\x7E\x30\x30\x33\x32\x35\x20\x31\x0D",   // ~00325 1
    "AV_MUTE_OFF"  => "\x7E\x30\x30\x33\x32\x35\x20\x30\x0D",   // ~00325 0
    "FREEZE"       => "\x7E\x30\x30\x30\x34\x20\x31\x0D",        // ~0004 1
    "UNFREEZE"     => "\x7E\x30\x30\x30\x34\x20\x30\x0D",        // ~0004 0
    "HDMI1"        => "\x7E\x30\x30\x31\x32\x20\x31\x0D",        // ~0012 1
    "HDMI2"        => "\x7E\x30\x30\x31\x32\x20\x31\x35\x0D",    // ~0012 15
    "VGA"          => "\x7E\x30\x30\x31\x32\x20\x35\x0D",        // ~0012 5
    "BAUD_RATE"    => "19200",
    "CHAR_BITS"    => "8",
    "STOP_BITS"    => "1",
    "PARITY"       => "none"
),


// ============================================================
// PANASONIC - Modern Laser Series (PT-VMZ / PT-VZ / PT-MZ)
// Protocol: STX (02) + ASCII text + ETX (03) binary wrapper
//           Same structure as existing PT-DW6300 and PT-LB50U entries
// Baud: 9600, 8N1, no flow control
// Source: Panasonic PT-VMZ series RS-232C Control Specifications
//         docs.connect.panasonic.com
// Covers: PT-VMZ61, PT-VMZ51, PT-VMZ41, PT-VMZ31, PT-VMW61,
//         PT-VZ580, PT-VW540, PT-MZ16K, PT-MZ13K, PT-MZ10K
// Command format: 02 ADZZZ;COMMAND 03
// SHUTTER = electronic blank — image mutes without powering off
// ============================================================

Array("NAME" => "Panasonic_PT_VMZ_Series",
    // Modern WUXGA/WXGA laser projectors (2018-2024)
    // Inputs: HD1=HDMI1, HD2=HDMI2, PC1=VGA/Computer, DP1=DisplayPort
    "ON"          => "\x02\x41\x44\x5A\x5A\x5A\x3B\x50\x4F\x4E\x03",                    // PON
    "OFF"         => "\x02\x41\x44\x5A\x5A\x5A\x3B\x50\x4F\x46\x03",                    // POF
    "HD1"         => "\x02\x41\x44\x5A\x5A\x5A\x3B\x49\x49\x53\x3A\x48\x44\x31\x03",   // IIS:HD1
    "HD2"         => "\x02\x41\x44\x5A\x5A\x5A\x3B\x49\x49\x53\x3A\x48\x44\x32\x03",   // IIS:HD2
    "PC1"         => "\x02\x41\x44\x5A\x5A\x5A\x3B\x49\x49\x53\x3A\x50\x43\x31\x03",   // IIS:PC1
    "DP1"         => "\x02\x41\x44\x5A\x5A\x5A\x3B\x49\x49\x53\x3A\x44\x50\x31\x03",   // IIS:DP1
    "SHUTTER_ON"  => "\x02\x41\x44\x5A\x5A\x5A\x3B\x4F\x53\x48\x3A\x31\x03",           // OSH:1
    "SHUTTER_OFF" => "\x02\x41\x44\x5A\x5A\x5A\x3B\x4F\x53\x48\x3A\x30\x03",           // OSH:0
    "BAUD_RATE"   => "9600",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),

Array("NAME" => "Panasonic_PT_MZ_Large_Venue",
    // High-lumen laser projectors: PT-MZ16K, PT-MZ13K, PT-MZ10K
    // Same command structure as VMZ series
    // Inputs: HD1=HDMI1, HD2=HDMI2, DP1=DisplayPort
    "ON"          => "\x02\x41\x44\x5A\x5A\x5A\x3B\x50\x4F\x4E\x03",
    "OFF"         => "\x02\x41\x44\x5A\x5A\x5A\x3B\x50\x4F\x46\x03",
    "HD1"         => "\x02\x41\x44\x5A\x5A\x5A\x3B\x49\x49\x53\x3A\x48\x44\x31\x03",
    "HD2"         => "\x02\x41\x44\x5A\x5A\x5A\x3B\x49\x49\x53\x3A\x48\x44\x32\x03",
    "DP1"         => "\x02\x41\x44\x5A\x5A\x5A\x3B\x49\x49\x53\x3A\x44\x50\x31\x03",
    "SHUTTER_ON"  => "\x02\x41\x44\x5A\x5A\x5A\x3B\x4F\x53\x48\x3A\x31\x03",
    "SHUTTER_OFF" => "\x02\x41\x44\x5A\x5A\x5A\x3B\x4F\x53\x48\x3A\x30\x03",
    "BAUD_RATE"   => "9600",
    "CHAR_BITS"   => "8",
    "STOP_BITS"   => "1",
    "PARITY"      => "none"
),

Array("NAME" => "-- Select Projector --",
    "PROTOCOL" => "NONE",
    "ON"       => "",
    "OFF"      => ""
)

);
?>
