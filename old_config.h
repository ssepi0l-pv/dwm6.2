/* See LICENSE file for copyright and license details. */
#define TERMINAL "st"
#define TERMCLASS "St"

/* appearance */
static const char *fonts[]          =   { "monospace:size=14", 
                                          "JoyPixels:size=10:antialias=true:autohint=true", 
                                          "Mononoki Nerd Font:size=9:antialias=true:autohint=true" 
                                          "FontAwesome:size=10:antialias=true:autohint=true" };
static const char dmenufont[]       = "monospace:size=10"; 
static const char normbordercolor[] = "#1d586a";
static const char normbgcolor[]     = "#1e586b";            //"#f442ef";
static const char normfgcolor[]     = "#ffffff";
static const char selbordercolor[]  = "#1d586a";
static const char selbgcolor[]      = "#030f18";            //"#9a0996";
static const char selfgcolor[]      = "#ddcbbf";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 1;        /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
        /* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
        { "Gimp",    NULL,     NULL,           0,         1,          0,           0,        -1 },
        { "Firefox", NULL,     NULL,           1 << 8,    0,          0,          -1,        -1 },
        { "St",      NULL,     NULL,           0,         0,          1,           0,        -1 },
        { NULL,      NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */

#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
 	{ "[@]",      spiral },
 	{ "[\\]",      dwindle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *layoutmenu_cmd = "layoutmenu.sh";

#include "shiftview.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_s,      togglebar,      {0} },
        // Mina bindings, chapter 0
	{ MODKEY,                       XK_Up,     focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_Down,   focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_Left,   setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_Right,  setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
        // Moya bindings, chapter 1
	{ MODKEY|ShiftMask,             XK_Up,     setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_Right,  setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_Left,   setlayout,      {.v = &layouts[2]} },
        { MODKEY,                       XK_r,      setlayout,      {.v = &layouts[3]} },
        { MODKEY|ShiftMask,             XK_r,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
//	{ MODKEY|ShiftMask,             XK_F11,    togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
        // Moi keybindings, chapter 2
        { MODKEY,                       XK_z,      spawn,          SHCMD("zim") },
        { MODKEY|ShiftMask,             XK_z,      spawn,          SHCMD("zoom") },
        { MODKEY,                       XK_Return, spawn,          SHCMD("emacsclient -c -a emacs") },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          SHCMD(TERMINAL) },
        { MODKEY,                       XK_l,      spawn,          SHCMD("discord") },
        { MODKEY|ShiftMask,             XK_l,      spawn,          SHCMD(TERMINAL " -e mc") },
        { MODKEY,                       XK_f,      spawn,          SHCMD("firefox") },
        { MODKEY|ShiftMask,             XK_f,      spawn,          SHCMD("alacritty")},
        { ShiftMask,                    XK_Print,  spawn,          SHCMD("rofi -show file-browser") },
        { 0,                            XK_Print,  spawn,          SHCMD("spectacle -g -f") },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
        { MODKEY|ShiftMask,             XK_p,      spawn,          SHCMD("rofi -show drun") },
        { MODKEY,                       XK_m,      spawn,          SHCMD(TERMINAL " -e neomutt") }, 
        { MODKEY|ShiftMask,             XK_m,      spawn,          SHCMD("keepass") }, 
        { MODKEY,                       XK_x,      spawn,          SHCMD(TERMINAL " -e htop") },
        { MODKEY|ShiftMask,             XK_x,      spawn,          SHCMD("pseint") },
        { MODKEY,                       XK_a,      spawn,          SHCMD("pavucontrol") },
        // Patches (look at line 56)
        { MODKEY,                       XK_n,      shiftview,      {.i = +1 } },
        { MODKEY,                       XK_b,      shiftview,      {.i = -1 } },
        // End patches.
        TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};



/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        layoutmenu,     {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

