/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx       = 0;   /* border pixel of windows */
static const int corner_radius           = 10;
static const unsigned int snap           = 32;  /* snap pixel */
static const unsigned int gappih         = 20;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 30;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int focusonwheel            = 0;
static const int vertpad                 = 10;  /* vertical padding of bar */
static const int sidepad                 = 10;  /* horizontal padding of bar */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = 1;
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */
static const unsigned int ulinepad = 5;         /* horizontal padding between the underline and tag */
static const unsigned int ulinestroke  = 2;     /* thickness / height of the underline */
static const unsigned int ulinevoffset = 0;     /* how far above the bottom of the bar the line should appear */
static const int ulineall = 0;                  /* 1 to show underline on all tags, 0 for just the active ones */



/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_NONE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_NONE;
static const char *fonts[]               = { "FiraCode Nerd Font:size=12", "Noto Color Emoji:autohint=true" };

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#bbbbbb";
static char normbgcolor[]                = "#222222";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#db8fd9";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#005577";
static char selbordercolor[]             = "#005577";
static char selfloatcolor[]              = "#005577";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#222222";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#eeeeee";
static char titleselbgcolor[]            = "#005577";
static char titleselbordercolor[]        = "#005577";
static char titleselfloatcolor[]         = "#005577";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#222222";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#eeeeee";
static char tagsselbgcolor[]             = "#005577";
static char tagsselbordercolor[]         = "#005577";
static char tagsselfloatcolor[]          = "#005577";

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";




static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};

static char *tagicons[][NUMTAGS] = {
	[DEFAULT_TAGS]        = { "", "", "3", "" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>" },
};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
  RULE(.wintype = WTYPE "_NET_WM_WINDOW_TYPE_NORMAL", .isfloating = 1)
	RULE(.title = "GNU Image Manipulation Program", .tags = 1 << 3)
  RULE(.class = "St", .tags = 1 << 1)
  RULE(.class = "Steam", .tags = 1 << 3)
  RULE(.class = "PrismLauncher", .tags = 1 << 3)
  RULE(.class = "Minecraft 1.8.9", .tags = 1 << 3, .monitor = 0)
  RULE(.class = "Minecraft* 1.19.2", .tags = 1 << 3, .monitor = 0)
  RULE(.class = "firefox", .tags = 1 << 0)
  RULE(.class = "Brave-browser", .tags = 1 << 0)
  RULE(.class = "Windscribe2", .isfloating = 1)
  RULE(.class = "Spotify", .tags = 1 << 2)
};

static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
	{  1,        0,     BAR_ALIGN_RIGHT,  width_systray,            draw_systray,           click_systray,           NULL,                    "systray" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status2d,           draw_status2d,          click_statuscmd,         NULL,                    "status2d" },
	{ -1,        0,     BAR_ALIGN_NONE,   width_wintitle,           draw_wintitle,          click_wintitle,          NULL,                    "wintitle" },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int decorhints  = 1;    /* 1 means respect decoration hints */



static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};


/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      comboview,      {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      combotag,       {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },



/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", NULL }; 
static const char *termcmd[]  = { "st" , NULL };

#define STATUSBAR "dwmblocks"

static const char* firefoxcmd[] = { "brave", NULL };
static const char* prismcmd[] = { "prismlauncher", NULL };

static const Key on_empty_keys[] = {
	/* modifier key            function                argument */
	{ 0,        XK_f,          spawn,                  {.v = firefoxcmd } },
	{ 0,        XK_p,          spawn,                  {.v = prismcmd } },
};

static const Key keys[] = {
	/* modifier                     key            function                argument */
	{ MODKEY,                       XK_s,          spawn,                  {.v = dmenucmd } },
	{ MODKEY,                       XK_t,          spawn,                  {.v = termcmd } },
	{ MODKEY,                       XK_z,          togglebar,              {0} },
	{ MODKEY,                       XK_j,          focusstack,             {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,             {.i = -1 } },
	{ MODKEY,                       XK_i,          incnmaster,             {.i = +1 } },
	{ MODKEY,                       XK_d,          incnmaster,             {.i = -1 } },
	{ MODKEY,                       XK_h,          setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_l,          setmfact,               {.f = +0.05} },
	{ MODKEY,                       XK_Return,     zoom,                   {0} },
	{ MODKEY|Mod4Mask,              XK_u,          incrgaps,               {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_u,          incrgaps,               {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_i,          incrigaps,              {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_i,          incrigaps,              {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_o,          incrogaps,              {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_o,          incrogaps,              {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_6,          incrihgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_6,          incrihgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_7,          incrivgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_7,          incrivgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_8,          incrohgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_8,          incrohgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_9,          incrovgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_9,          incrovgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_0,          togglegaps,             {0} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,          defaultgaps,            {0} },
	{ MODKEY,                       XK_Tab,        view,                   {0} },
	{ MODKEY|ShiftMask,             XK_c,          killclient,             {0} },
	{ MODKEY|ShiftMask,             XK_q,          quit,                   {0} },
	{ MODKEY,                       XK_u,          focusurgent,            {0} },
	{ MODKEY|ShiftMask,             XK_F5,         xrdb,                   {.v = NULL } },
	{ MODKEY,                       XK_e,          setlayout,              {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,          setlayout,              {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,          setlayout,              {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} },
	{ MODKEY,                       XK_space,      togglesticky,           {0} },
  { MODKEY|ShiftMask,             XK_f,          togglefullscreen,       {0} },
	{ MODKEY,                       XK_comma,      focusmon,               {.i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },
	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button1,        sigstatusbar,   {.i = 1 } },
	{ ClkStatusText,        0,                   Button2,        sigstatusbar,   {.i = 2 } },
	{ ClkStatusText,        0,                   Button3,        sigstatusbar,   {.i = 3 } },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};
