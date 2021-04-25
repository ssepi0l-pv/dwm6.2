/* See LICENSE file for copyright and license details. */

#define TERMINAL "st"
#define TERMCLASS "St"

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 35;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "FiraMono Nerd Font:size=11:antialias=true:autohint=true", 
                                        "Material Design Icons:style:size=12:antialias=true:autohint=true",
                                        "Font Awesome 5 Brands:size=9:antialias=true:autohint=true", 
                                        "Mononoki Nerd Font:size=9:antialias=true:autohint=true"
                        };
static const char dmenufont[]       = "monospace:size=10";       /* dmenu font                  */ 
static const char col_bgb[]         = "#000000";                 /* tar background              */
static const char col_gray2[]       = "#444444";                 /* bordercolor                 */
static const char col_gray3[]       = "#bbbbbb";                 /* not highlighted text        */
static const char col_gray4[]       = "#e7e2bc";                 /* highlighted text            */
static const char col_bg[]          = "#141414";                 /* bar background              */ 
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_bgb, col_gray2 },
	[SchemeSel]  = { col_gray4, col_bg,  col_bg    },
};

/* tagging */
static const char *tags[] = { "", "", " ﭮ ", "", "嗢", "", "", "", "" };
static const char *alttags[] = { "> ", "> ", "> ﭮ", "> ", "> 嗢", "> ", "> ", "> ", "> " };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
 	{ "[@]",      spiral },
 	{ "[\\]",     dwindle },
        { "|M|",      centeredmaster },
        { ">M>",      centeredfloatingmaster },
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

#define STATUSBAR "dwmblocks"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]     = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_bgb, "-nf", col_gray3, "-sb", col_bg, "-sf", col_gray4, NULL };
static const char *termcmd[]      = { "st", NULL };
static const char *layoutmenu_cmd = "layoutmenu.sh";
static const char *editor         = "emacsclient -c a emacs"

#include "shiftview.c"

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_s,      togglebar,      {0} },
	{ MODKEY,                       XK_Up,     focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_Down,   focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_Left,   setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_Right,  setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_Up,     setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_Right,  setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_Left,   setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_r,      setlayout,      {.v = &layouts[3]} },
    { MODKEY|ShiftMask,             XK_r,      setlayout,      {.v = &layouts[4]} },
    { MODKEY,                       XK_u,      setlayout,      {.v = &layouts[5]} },
    { MODKEY|ShiftMask,             XK_u,      setlayout,      {.v = &layouts[6]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_F11,    togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    { MODKEY,                       XK_z,      spawn,          SHCMD("zim") },
    { MODKEY|ShiftMask,             XK_z,      spawn,          SHCMD("zoom") },
    { MODKEY,                       XK_Return, spawn,          {.v = editor } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          SHCMD(TERMINAL) },
    { MODKEY,                       XK_l,      spawn,          SHCMD("discord") },
    { MODKEY|ShiftMask,             XK_l,      spawn,          SHCMD(TERMINAL " -e ranger") },
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
    { MODKEY,                       XK_a,      spawn,          SHCMD("pavucontrol") }, // mostly for when my mic gets fucked or something :)
    { ShiftMask,                    XK_F10,    spawn,          SHCMD("pamixer -t") },
    { 0,                            XK_F11,    spawn,          SHCMD("pamixer -d 10") },
    { 0,                            XK_F12,    spawn,          SHCMD("pamixer -i 10") },
    { ShiftMask,                    XK_F11,    spawn,          SHCMD("mpc volume -10") },
    { ShiftMask,                    XK_F12,    spawn,          SHCMD("mpc volume +10") },
    { MODKEY,                       XK_F5,     spawn,          SHCMD("light -U 10") },
    { MODKEY,                       XK_F6,     spawn,          SHCMD("light -A 10") },
    { MODKEY,                       XK_bar,    spawn,          SHCMD(TERMINAL " -e ncmpcpp") },
    { MODKEY|ControlMask,           XK_comma,  spawn,          SHCMD("mpc prex") },
    { MODKEY|ControlMask,           XK_minus,  spawn,          SHCMD("mpc next") },
    { MODKEY,                       XK_n,      shiftview,      {.i = +1 } },
    { MODKEY,                       XK_b,      shiftview,      {.i = -1 } },
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
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        layoutmenu,     {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

