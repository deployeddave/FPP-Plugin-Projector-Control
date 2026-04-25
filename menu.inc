<?php
# FPP-Plugin-Projector-Control — menu.inc
#
# Modern FPP menu format (FPP 7+). Replaces the old output_menu.inc.
#
# This file handles ALL menu sections in one place. FPP calls it once
# per menu section with $menu set to the current section name:
#   'status'  → Status/Control menu
#   'content' → Content Setup menu
#   'output'  → Channel Outputs menu
#   'help'    → Help menu
#
# The 'wrap' => 1 flag tells FPP to inject its standard header, nav,
# and footer around the page content (which is what we want for all
# plugin pages). Set wrap => 0 only for raw/API endpoints.

$menuEntries = Array(

    // ── Content Setup → Projector Control ──────────────────────────────
    // This is where users configure the plugin. Appears under the
    // "Content Setup" top-level nav dropdown alongside playlists,
    // file manager, etc.
    Array(
        'text' => 'Projector Control',
        'type' => 'content',
        'page' => 'plugin_setup.php',
        'wrap' => 1
    ),

    // ── Help → Projector Control Help ──────────────────────────────────
    // Adds a "Projector Control Help" entry to FPP's Help dropdown menu.
    // Also triggered by F1 when the user is on plugin_setup.php.
    // The file is help/plugin_setup.php — FPP's F1 hook builds this
    // path automatically from the current page name.
    Array(
        'text' => 'Projector Control Help',
        'type' => 'help',
        'page' => 'help/plugin_setup.php',
        'wrap' => 1
    ),

);

// ── Standard menu rendering loop ─────────────────────────────────────────────
// Do not modify below this line. This is the standard pattern used by all
// modern FPP plugins. It renders only the entries matching the current
// $menu section that FPP is building.

foreach ($menuEntries as $entry) {

    if ($entry['type'] != $menu)
        continue;

    if (preg_match('/^http.?:\/\//', $entry['page'])) {
        // External URL — open in new tab
        printf("<li><a href='%s' target='_blank'>%s</a></li>\n",
               $entry['page'], $entry['text']);
    } else {
        $nopage = '';
        if (isset($entry['wrap']) && ($entry['wrap'] == 0))
            $nopage = '&nopage=1';

        printf("<li><a href='plugin.php?plugin=%s&page=%s%s'>%s</a></li>\n",
               $plugin, $entry['page'], $nopage, $entry['text']);
    }
}
?>
