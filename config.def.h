/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 0;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "SourceCodePro:medium:size=13" };
static const char col_gray1[]       = "#000000";
static const char col_gray2[]       = "#000000";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#427b58";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
	{ NULL,       NULL,  "Floating_Term", 0,            1,           -1 },
	{ NULL,       NULL,  "Floating_IMG",  0,            1,           -1 },
	{ "Nsxiv","Floating_IMG", NULL,       0,            1,           -1 },
	{ NULL,       NULL, "Fcitx Configuration", 0,       1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int refreshrate = 120;  /* refresh rate (per second) for client move/resize */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "[D]",      deck },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ ControlMask,                  KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run" };
static const char *termcmd[]  = { "st", NULL };

#include "movestack.c"

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_v,      spawn,          SHCMD("st -T \"Floating_Term\" -A 0.9 abduco -A dvtm dvtm-status") },
	{ MODKEY,                       XK_r,      spawn,          SHCMD("st sh -c 'sleep 0.03 && lf'") },
	{ MODKEY,                       XK_q,      spawn,          SHCMD("qutebrowser") },
	{ MODKEY,                       XK_minus,  spawn,          SHCMD("${HOME}/.local/bin/audio sink --minus10") },
	{ MODKEY|ShiftMask,             XK_minus,  spawn,          SHCMD("${HOME}/.local/bin/audio sink --minus") },
	{ MODKEY,                       XK_equal,  spawn,          SHCMD("${HOME}/.local/bin/audio sink --plus10") },
	{ MODKEY|ShiftMask,             XK_equal,  spawn,          SHCMD("${HOME}/.local/bin/audio sink --plus") },
	{ MODKEY,                       XK_BackSpace, spawn,       SHCMD("${HOME}/.local/bin/audio sink --mute") },
	{ MODKEY|ControlMask,           XK_minus,  spawn,          SHCMD("${HOME}/.local/bin/audio source --minus10") },
	{ MODKEY|ControlMask|ShiftMask, XK_minus,  spawn,          SHCMD("${HOME}/.local/bin/audio source --minus") },
	{ MODKEY|ControlMask,           XK_equal,  spawn,          SHCMD("${HOME}/.local/bin/audio source --plus10") },
	{ MODKEY|ControlMask|ShiftMask, XK_equal,  spawn,          SHCMD("${HOME}/.local/bin/audio source --plus") },
	{ MODKEY|ControlMask,           XK_BackSpace,    spawn,    SHCMD("${HOME}/.local/bin/audio source --mute") },
	{ MODKEY,                       XK_bracketleft,  spawn,    SHCMD("${HOME}/.local/bin/bright --minus10") },
	{ MODKEY|ShiftMask,             XK_bracketleft,  spawn,    SHCMD("${HOME}/.local/bin/bright --minus") },
	{ MODKEY,                       XK_bracketright, spawn,    SHCMD("${HOME}/.local/bin/bright --plus10") },
	{ MODKEY|ShiftMask,             XK_bracketright, spawn,    SHCMD("${HOME}/.local/bin/bright --plus") },
	{ MODKEY|ControlMask|ShiftMask, XK_bracketleft,  spawn,    SHCMD("${HOME}/.local/bin/bright --min") },
	{ MODKEY|ControlMask|ShiftMask, XK_bracketright, spawn,    SHCMD("${HOME}/.local/bin/bright --max") },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          SHCMD("i3lock -i ${HOME}/.local/share/lockscreen -f") },
	{ MODKEY|ShiftMask,             XK_e,      spawn,          SHCMD("${HOME}/.local/bin/hibe") },
	{ ControlMask,                  XK_space,  spawn,          SHCMD("fcitx5-remote -t") },
	{ MODKEY,                       XK_n,      spawn,          SHCMD("dunstctl history-pop") },
	{ MODKEY|ShiftMask,             XK_n,      spawn,          SHCMD("dunstctl close") },
	{ MODKEY|ControlMask|ShiftMask, XK_n,      spawn,          SHCMD("dunstctl close-all") },
	{ MODKEY,                       XK_y,      spawn,          SHCMD("${HOME}/.local/bin/shoot") },
	{ MODKEY|ShiftMask,             XK_y,      spawn,          SHCMD("${HOME}/.local/bin/shoot --geo") },
	{ MODKEY|ControlMask,           XK_y,      spawn,          SHCMD("${HOME}/.local/bin/shoot --all") },
	{ MODKEY,                       XK_c,      spawn,          SHCMD("clipmenu") },
	{ MODKEY,                       XK_a,      spawn,          SHCMD("${HOME}/.local/bin/address") },
	{ MODKEY|ShiftMask,             XK_a,      spawn,          SHCMD("${HOME}/.local/bin/address --record") },
	{ MODKEY|ControlMask,           XK_a,      spawn,          SHCMD("${HOME}/.local/bin/address --multi") },
	{ MODKEY|ControlMask,           XK_space,  spawn,          SHCMD("mpc --toggle && ${HOME}/.local/bin/lsmus") },
	{ MODKEY|ControlMask,           XK_p,      spawn,          SHCMD("mpc prev") },
	{ MODKEY|ControlMask,           XK_n,      spawn,          SHCMD("mpc next") },
    { MODKEY|ControlMask,           XK_s,      spawn,          SHCMD("${HOME}/.local/bin/sk") },
    { MODKEY|ShiftMask,             XK_b,      spawn,          SHCMD("redshift -P -O 5000") },
    { MODKEY|ControlMask,           XK_b,      spawn,          SHCMD("redshift -x") },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_semicolon, shiftview,   { .i = -1 } },
	{ MODKEY,                       XK_apostrophe,shiftview,   { .i = 1 } },
	{ MODKEY|ShiftMask,             XK_semicolon, shifttag,    {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_apostrophe,shifttag,    {.i = +1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY|ControlMask,           XK_h,      focusmaster,    {0} },
	{ MODKEY|ControlMask,           XK_l,      focusmaster,    {0} },
	{ MODKEY,                       XK_z,      zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_backslash,view,         {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,             XK_u,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_o,      setlayout,      {.v = &layouts[5]} },
	{ MODKEY|ShiftMask,             XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_e,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|ControlMask,           XK_bracketright, setgaps,  {.i = -1 } },
	{ MODKEY|ControlMask,           XK_bracketleft,  setgaps,  {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      spawn,          SHCMD("${HOME}/.local/bin/exiorg -dwm") },
	{ MODKEY|ShiftMask,             XK_s,      togglesticky,   {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
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

