/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:34:32 by sel-bouy          #+#    #+#             */
/*   Updated: 2023/12/11 11:44:45 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <libc.h>

int main()
{
	int fd = open("text.txt", O_CREAT | O_RDWR, 0777);
	int fd2 = open("test.txt", O_CREAT | O_RDWR, 0777);
	int fd3 = open("txt.txt", O_CREAT | O_RDWR, 0777);
	
	char *s = get_next_line(fd);
	char *s2 = get_next_line(fd2);
	char *s3 = get_next_line(fd3);
	
	while (s != NULL && s2 != NULL && s3 != NULL)
	{
		printf("%s\n%s\n%s\n", s, s2, s3);
		s = get_next_line(fd);
	    s2 = get_next_line(fd2);
	    s3 = get_next_line(fd3);
		
	}
	// printf("%s", s);
	// printf("%s", s2);
	// printf("%s", s3);
	// s = get_next_line(fd);
	// printf("%s", s);
	// printf("%s", s2);
	// printf("%s", s3);
	// printf("%s", s);
	// printf("%s", s2);
	
	// int fd = open("text.txt", O_RDWR, 0777);
	// char *s = get_next_line(fd);
	// while (s != NULL)
	// {
	// 	printf("%s", s);
	// 	s = get_next_line(fd);
	// }
}
// void funct()
// {
// 	static int i = 12;
// 	i++;
// 	printf("this is a static variable : %d\n", i);
// }
// int main(void)
// {
// 	funct();
// 	funct();
// 	funct();
// 	return 0;
// }
// output :
// 		13
// 		14
// 		15
// output : (if thre is not a 'static variable' )
// 		13
// 		13
// 		13
// }
