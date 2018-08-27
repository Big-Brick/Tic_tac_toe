/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncursesIO.class.Base.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzikovs <adzikovs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 13:02:34 by adzikovs          #+#    #+#             */
/*   Updated: 2018/08/27 14:27:45 by adzikovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <regex>

#include "IO/ncursesIO.class.hpp"

#ifdef NCURSES_ON

#include <ncurses.h>

void				ncursesIO::Init(void)
{
	int		y;
	int 	x;

	initscr();
	getmaxyx(stdscr, y, x);
	if (y < 3 || x < 3)
		throw ncursesIO::WindowTooSmallError(y, x);
}

void				ncursesIO::DeInit(void)
{
	endwin();
}

std::string			ncursesIO::ReadInput(void)
{
	char								Buff[10];

	bzero(Buff, 10);
	getnstr(Buff, 9);
	return (std::string(Buff));
}

#endif