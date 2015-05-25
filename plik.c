#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int tmp,ileb,ilosc=0,ile_slow=0;
	char t = 0;
	tmp = open(argv[1],O_RDONLY);

do
{
	ileb = read(tmp, &t, 1 );
	if (((t >= 'a') && (t <= 'z')) || ((t >= 'A') && (t <= 'Z')) || ((t >= '0') && (t <= '9')) || (t == '_'))
	{
		ilosc=ilosc+1;
	}
	else if (ilosc != 0)
	{
		ile_slow=ile_slow+1;
		ilosc = 0;
	}

}
while (ileb != 0);
printf ("ilosc słów:%d ", ile_slow);

	close(tmp);
	return 0;
}