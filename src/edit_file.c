static void edit_file(Byte * fn)
{
	char c;
	int cnt, size, ch;

	rawmode();
	rows = 24;
	columns = 80;
	ch= -1;

	new_screen(rows, columns);	// get memory for virtual screen

	cnt = file_size(fn);	// file size
	size = 2 * cnt;		// 200% of file size
	new_text(size);		// get a text[] buffer
	screenbegin = dot = end = text;
	//将文本读入内存
	if (fn != 0) {
		ch= file_insert(fn, text, cnt);
	}
	//空的就创建
	if (ch < 1) {
		(void) char_insert(text, '\n');	// start empty buf with dummy line
	}
	file_modified = FALSE;
	err_method = 1;		// flash
	last_forward_char = last_input_char = '\0';
	crow = 0;
	ccol = 0;
	edit_status();
	editing = 1;
	cmd_mode = 0;		// 0=command  1=insert  2='R'eplace
	cmdcnt = 0;
	tabstop = 8;
	offset = 0;			// no horizontal offset
	c = '\0';
	redraw(FALSE);			// dont force every col re-draw
	show_status_line();

	//------This is the main Vi cmd handling loop -----------------------
	while (editing > 0) {
		last_input_char = c = get_one_char();	// get a cmd from user
		do_cmd(c);		// execute the user command
		//
		// poll to see if there is input already waiting. if we are
		// not able to display output fast enough to keep up, skip
		// the display update until we catch up with input.
		if (mysleep(0) == 0) {
			// no input pending- so update output
			refresh(FALSE);
			show_status_line();
		}
	}
	//-------------------------------------------------------------------

	place_cursor(rows, 0, FALSE);	// go to bottom of screen
	clear_to_eol();		// Erase to end of line
	cookmode();
}