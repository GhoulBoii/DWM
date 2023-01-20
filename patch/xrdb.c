void
loadxrdb()
{
	Display *display;
	char * resm;
	XrmDatabase xrdb;
	char *type;
	XrmValue value;

	display = XOpenDisplay(NULL);

	if (display != NULL) {
		resm = XResourceManagerString(display);

		if (resm != NULL) {
			xrdb = XrmGetStringDatabase(resm);

			if (xrdb != NULL) {
				XRDB_LOAD_COLOR("dwm.color6", normfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", normbgcolor);
				XRDB_LOAD_COLOR("dwm.color0", normbordercolor);
				XRDB_LOAD_COLOR("dwm.color0", normfloatcolor);
				XRDB_LOAD_COLOR("dwm.color0", selfgcolor);
				XRDB_LOAD_COLOR("dwm.color14", selbgcolor);
				XRDB_LOAD_COLOR("dwm.color8", selbordercolor);
				XRDB_LOAD_COLOR("dwm.color8", selfloatcolor);
				XRDB_LOAD_COLOR("dwm.color6", titlenormfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", titlenormbgcolor);
				XRDB_LOAD_COLOR("dwm.color0", titlenormbordercolor);
				XRDB_LOAD_COLOR("dwm.color0", titlenormfloatcolor);
				XRDB_LOAD_COLOR("dwm.color0", titleselfgcolor);
				XRDB_LOAD_COLOR("dwm.color14", titleselbgcolor);
				XRDB_LOAD_COLOR("dwm.color8", titleselbordercolor);
				XRDB_LOAD_COLOR("dwm.color8", titleselfloatcolor);
				XRDB_LOAD_COLOR("dwm.color6", tagsnormfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", tagsnormbgcolor);
				XRDB_LOAD_COLOR("dwm.color0", tagsnormbordercolor);
				XRDB_LOAD_COLOR("dwm.color0", tagsnormfloatcolor);
				XRDB_LOAD_COLOR("dwm.color0", tagsselfgcolor);
				XRDB_LOAD_COLOR("dwm.color14", tagsselbgcolor);
				XRDB_LOAD_COLOR("dwm.color8", tagsselbordercolor);
				XRDB_LOAD_COLOR("dwm.color0", tagsselfloatcolor);
				XRDB_LOAD_COLOR("dwm.color6", hidnormfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", hidnormbgcolor);
				XRDB_LOAD_COLOR("dwm.color0", hidselfgcolor);
				XRDB_LOAD_COLOR("dwm.color14", hidselbgcolor);
				XRDB_LOAD_COLOR("dwm.color6", urgfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", urgbgcolor);
				XRDB_LOAD_COLOR("dwm.color8", urgbordercolor);
				XRDB_LOAD_COLOR("dwm.color0", urgfloatcolor);

				XrmDestroyDatabase(xrdb);
			}
		}
	}

	XCloseDisplay(display);
}

void
xrdb(const Arg *arg)
{
	loadxrdb();
	int i;
	for (i = 0; i < LENGTH(colors); i++)
		scheme[i] = drw_scm_create(drw, colors[i],
		ColCount
		);
	focus(NULL);
	arrange(NULL);
}

