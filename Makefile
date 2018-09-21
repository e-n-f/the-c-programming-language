all: 1.01-hello 1.02-fahr-float 1.02-fahr 1.03-for 1.04-define 1.05-characters-assign 1.05-characters 1.05.02-charcount-for 1.05.02-charcount 1.05.03-linecount 1.05.04-wordcount-ctype 1.05.04-wordcount 1.06-digits 1.07-power 1.08-power2 1.09-maxline 3.07-trim 4.01-fgrep 5.06-sort 5.10-echo 5.10-echo2 5.10-echo3 5.10-find 5.10-options

1.01-hello: 1.01-hello.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 1.01-hello 1.01-hello.c

1.02-fahr-float: 1.02-fahr-float.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 1.02-fahr-float 1.02-fahr-float.c

1.02-fahr: 1.02-fahr.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 1.02-fahr 1.02-fahr.c

1.03-for: 1.03-for.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 1.03-for 1.03-for.c

1.04-define: 1.04-define.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 1.04-define 1.04-define.c

1.05-characters-assign: 1.05-characters-assign.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 1.05-characters-assign 1.05-characters-assign.c

1.05-characters: 1.05-characters.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 1.05-characters 1.05-characters.c

1.05.02-charcount-for: 1.05.02-charcount-for.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 1.05.02-charcount-for 1.05.02-charcount-for.c

1.05.02-charcount: 1.05.02-charcount.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 1.05.02-charcount 1.05.02-charcount.c

1.05.03-linecount: 1.05.03-linecount.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 1.05.03-linecount 1.05.03-linecount.c

1.05.04-wordcount-ctype: 1.05.04-wordcount-ctype.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 1.05.04-wordcount-ctype 1.05.04-wordcount-ctype.c

1.05.04-wordcount: 1.05.04-wordcount.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 1.05.04-wordcount 1.05.04-wordcount.c

1.06-digits: 1.06-digits.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 1.06-digits 1.06-digits.c

1.07-power: 1.07-power.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 1.07-power 1.07-power.c

1.08-power2: 1.08-power2.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 1.08-power2 1.08-power2.c

1.09-maxline: 1.09-maxline.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 1.09-maxline 1.09-maxline.c

3.07-trim: 3.07-trim.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 3.07-trim 3.07-trim.c

4.01-fgrep: 4.01-fgrep.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 4.01-fgrep 4.01-fgrep.c

5.06-sort: 5.06-sort.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 5.06-sort 5.06-sort.c

5.10-echo: 5.10-echo.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 5.10-echo 5.10-echo.c

5.10-echo2: 5.10-echo2.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 5.10-echo2 5.10-echo2.c

5.10-echo3: 5.10-echo3.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 5.10-echo3 5.10-echo3.c

5.10-find: 5.10-find.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 5.10-find 5.10-find.c

5.10-options: 5.10-options.c
	cc -g -Wall -Wconversion -I. -O3 -std=c11 -o 5.10-options 5.10-options.c

