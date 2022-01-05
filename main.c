/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 18:45:33 by tel-bara      #+#    #+#                 */
/*   Updated: 2022/01/05 17:03:45 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// brew install nasm
// nasm -f macho64 ft_strcmp.s ft_strcpy.s ft_strlen.s ft_write.s
// gcc main.c ft_strlen.o ft_strcpy.o ft_strcmp.o ft_write.o

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define DARKGRAY "\033[0;38m"
#define STRLEN(x) test_strlen(x)
#define STRCPY(a, b) test_strcpy(a, b)
#define STRCPY_LEN(a, b) test_strcpy_len(a, b)
#define STRCMP(a, b) test_strcmp(a, b)
#define WRITE(a, b, c) test_write(a, b, c)
#define READ(a, b) test_read(a, b)

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

int	test_strlen(char *s)
{
	char	*test;
	size_t	res;
	size_t	res_ft;

	test = strdup(s);
	res = strlen(test);
	res_ft = ft_strlen(test);
	if (res == res_ft)
	{
		printf(GREEN);
		printf("%6.4s", " OK ");
	}
	else
	{
		printf(RED);
		printf("%6.4s", "NOPE");
	}
	printf(DARKGRAY);
	if (res < 16)
		printf("  input: \"%-16.16s", strcat(test, "\""));
	else
	{
		strcpy(test + 12, "...\"");
		printf("  input: \"%-16.16s", test);
	}
	printf("         %3zu %8zu\n", res, res_ft);
	free(test);
	return (1);
}

int	test_strcpy(char *s1, char *s2)
{
	char	*test1;
	char	*test1_ft;
	char	*s2_org;
	char	*s1_org;
	int		res;
	int		res2;

	s1_org = strdup(s1);
	test1 = strdup(s1);
	s2_org = strdup(s2);
	test1_ft = strdup(s1);

	res = strcmp(strcpy(test1, s2_org), ft_strcpy(test1_ft, s2_org));
	res2 = strcmp(test1, test1_ft);
	if (!res && !res2)
	{
		printf(GREEN);
		printf("%6.4s", " OK ");
	}
	else
	{
		printf(RED);
		printf("%6.4s", "NOPE");
	}
	printf(DARKGRAY);
	if (strlen(s1_org) < 11)
		printf("  input: \"%-11.11s", strcat(s1_org, "\""));
	else
	{
		strcpy(s1_org + 7, "...\"");
		printf("  input: \"%-11.11s", s1_org);
	}
	if (strlen(s2_org) < 11)
		printf(" \"%-11.11s", strcat(s2_org, "\""));
	else
	{
		strcpy(s2_org + 7, "...\"");
		printf(" \"%-11.11s", s2_org);
	}
	if (strlen(test1_ft) < 11)
		printf(" \"%-11.11s\n", strcat(test1_ft, "\""));
	else
	{
		strcpy(test1_ft + 7, "...\"");
		printf(" \"%-11.11s\n", test1_ft);
	}
	free(test1);
	free(s2_org);
	free(s1_org);
	free(test1_ft);
	return (1);
}

int	test_strcpy_len(char *s, int len)
{
	char	*test;
	char	*test_ft;
	char	*s_org;
	int		res;
	int		res2;

	s_org = strdup(s);
	test = calloc(len + 1, 1);
	test_ft = calloc(len + 1, 1);

	res = strcmp(strcpy(test, s_org), ft_strcpy(test_ft, s_org));
	res2 = strcmp(test, test_ft);
	if (!res && !res2)
	{
		printf(GREEN);
		printf("%6.4s", " OK ");
	}
	else
	{
		printf(RED);
		printf("%6.4s", "NOPE");
	}
	printf(DARKGRAY);
	if (strlen(s_org) < 11)
		printf("  input: \"%-11.11s", strcat(s_org, "\""));
	else
	{
		strcpy(s_org + 7, "...\"");
		printf("  input: \"%-11.11s", s_org);
	}
	printf(" %-12d", len);
	if (strlen(test_ft) < 11)
		printf(" \"%-11.11s\n", strcat(test_ft, "\""));
	else
	{
		strcpy(test_ft + 7, "...\"");
		printf(" \"%-11.11s\n", test_ft);
	}
	free(test);
	free(s_org);
	free(test_ft);
	return (1);
}

int	test_strcmp(char *s1, char *s2)
{
	char	*test1;
	char	*test2;
	int		res;
	int		res_ft;

	test1 = strdup(s1);
	test2 = strdup(s2);

	res = strcmp(test1, test2);
	res_ft = ft_strcmp(test1, test2);
	if (res == res_ft)
	{
		printf(GREEN);
		printf("%6.4s", " OK ");
	}
	else
	{
		printf(RED);
		printf("%6.4s", "NOPE");
	}
	printf(DARKGRAY);
	if (strlen(test1) < 11)
		printf("  input: \"%-11.11s", strcat(test1, "\""));
	else
	{
		strcpy(test1 + 7, "...\"");
		printf("  input: \"%-11.11s", test1);
	}
	if (strlen(test2) < 11)
		printf(" \"%-11.11s", strcat(test2, "\""));
	else
	{
		strcpy(test2 + 7, "...\"");
		printf(" \"%-11.11s", test2);
	}
	printf(" %3d %8d\n", res, res_ft);
	free(test1);
	free(test2);
	return (1);
}

int	test_write(char *s, int fd, size_t nbyte)
{
	ssize_t	res;
	ssize_t	res_ft;

	if (fd == 1)
	{
		write(1, DARKGRAY, 7);
		write(1, "   ::   write:   \t", 18);
		res = write(fd, s, nbyte);
		write(1, "\n", 1);
		write(1, "   ::   ft_write:\t", 18);
		res_ft = ft_write(fd, s, nbyte);
		write(1, "\n", 1);
	}
	else
	{
		printf(DARKGRAY);
		res = write(fd, s, nbyte);
		if (res >= 0)
			printf("   ::%9s   \twriting %lu bytes of %s to file %d\n", "write:", nbyte, s, fd);
		else
		{
			printf("   ::%9s   \t%s - errno %i - [%s]\n", "write:", s, errno, strerror(errno));
			errno = 0;
		}
		res_ft = ft_write(fd, s, nbyte);
		if (res >= 0)
			printf("   ::%12s\twriting %lu bytes of %s to file %d\n", "ft_write:", nbyte, s, fd);
		else
			printf("   ::%12s\t%s - errno %i - [%s]\n", "ft_write:", s, errno, strerror(errno));
	}
	if (res == res_ft)
	{
		printf(GREEN);
		printf("%6.4s", " OK ");
	}
	else
	{
		printf(RED);
		printf("%6.4s", "NOPE");
	}
	printf(DARKGRAY);
	printf("  Return values:\t\t\t%4zd\t%6zd\n\n", res, res_ft);
	return (1);
}

int	main(void)
{
	printf("\n");
	printf(PURPLE);
	printf("TESTING TIJMEN'S LIBASM...\n");
	
	//TESTING STRLEN
	printf(CYAN);
	printf("> Testing Tijmen's ft_strlen...\t\tstrlen\tft_strlen\n");
	STRLEN("Hello");
	STRLEN("");
	STRLEN("Nederland is een schoon land. Een land met een prachtige natuur, een schone lucht en een goed milieu. Een land om trots op te zijn. Ons Nederlandse landschap is uniek en wereldberoemd. Een landschap om zuinig op te zijn en onze bescherming verdient tegen het vernietigende klimaatbeleid zoals windturbines en zonneparken. \
CO2 is een voedingsbron voor alles wat groeit en bloeit. Klimaatbeleid, dat draait om het terugdringen van de CO2-uitstoot, heeft dan ook bar weinig te maken met natuur of milieu. Niemand is tegen een groene leefomgeving of een goed milieu, ook de PVV niet. Waar de PVV wel tegen is, is zinloos, onbetaalbaar klimaatbeleid. \
De mens is verantwoordelijk voor slechts een paar procent van alle CO2 in de atmosfeer. Het is dan ook een illusie dat de mens het klimaat wezenlijk zou kunnen beïnvloeden. Het kleine Nederland is verantwoordelijk voor maar 0,35% van de totale wereldwijde CO2-uitstoot: verwaarloosbaar. Het Nederlandse klimaatbeleid leidt tot een mindere opwarming van de aarde van slechts 0,00007 graden: óók verwaarloosbaar. Maar toch is CO2 tot  de grote vijand  verklaard. De obsessieve, verregaande strijd tegen CO2- uitstoot vertoont inmiddels dictatoriale trekjes. Nederlanders die normaal hun leven willen leiden, wordt bij alles wat ze doen een klimaatschuldgevoel aangepraat en angst voor klimaatverandering aangejaagd. \
Klimaatbeleid kost vele, vele miljarden en stort huishoudens de financiële afgrond in. Klimaatbeleid is nergens goed voor, maar perkt onze vrije manier van leven des te ingrijpender in: we worden geregeerd door klimaathippies die willen dat we onze woningen voor vele tienduizenden euro s van het gas af halen, terwijl gas de schoonste fossiele brandstof is. Ze willen dat we in onbetaalbare elektrische auto s gaan rijden. Ze willen dat we minder vliegen, minder vlees eten. Het wordt ons allemaal opgedrongen, en dat moet stoppen. \
Tegelijkertijd worden ons land en onze Noordzee volgebouwd met subsidie-slurpende windturbines. Bomen worden verbrand in vervuilende biomassacentrales. Weilanden worden opgeofferd voor zonneparken. Ons prachtige landschap wordt kapotgemaakt onder het mom van een niet-bestaande  klimaatcrisis . Ook dat moet stoppen. \
De PVV zegt: wij laten ons niet de les lezen door wereldvreemde klimaatpredikers. Daarom maken we een einde aan de totaal geradicaliseerde klimaatgekte: de Klimaatwet, het Klimaatakkoord en alle onzinnige maatregelen gaan onmiddellijk de prullenbak in. Alle klimaat- en duurzaamheidssubsidies schaffen we direct af. Geen geld meer voor onzinnige linkse hobby s, maar méér geld in de portemonnee van onze mensen. \
Want door alle miljardensubsidies die aan de groene terreur worden verspild, gaat de energierekening omhoog en omhoog. Terwijl huishoudens in Duitsland geld toekrijgen als ze een gasaansluiting nemen, wordt gas in Nederland steeds duurder gemaakt. \
Nu al leven honderdduizenden huishoudens in energiearmoede: zij kunnen de energierekening nauwelijks tot niet meer betalen en zitten vaak letterlijk op de bank te rillen van de kou. Energie is een basisbehoefte, maar door de klimaatwaanzin is er een peperduur luxeproduct van gemaakt. \
De PVV kiest voor een fors lagere, betaalbare energierekening: we stoppen met de geldverslindende energietransitie en verlagen de energiebelasting. Woningen worden niet van het gas af gehaald. De afschaffing van de gasaansluitplicht draaien we terug, waardoor nieuwbouwwoningen weer een vertrouwde gasaansluiting kunnen krijgen - op het beste en meest betrouwbare gasnet ter wereld. Gas komt niet langer uit Groningen, maar halen we uit de bodem van de Noordzee en importeren we uit landen als Noorwegen, Engeland etc. – zoals nu al gebeurt. Onze kolencentrales, die tot de schoonste ter wereld behoren, blijven open. Ook worden er kerncentrales bijgebouwd die veiliger zijn dan ooit. Daarnaast zetten we in op thorium.");
	
	//TESTING STRCPY
	printf(CYAN);
	printf("\n\n> Testing Tijmen's ft_strcpy...\t\tft_strcpy\n");
	STRCPY("Hello", "Hi");
	STRCPY("Hello", "");
	STRCPY_LEN("Nederland is een schoon land. Een land met een prachtige natuur, een schone lucht en een goed milieu. Een land om trots op te zijn. Ons Nederlandse landschap is uniek en wereldberoemd. Een landschap om zuinig op te zijn en onze bescherming verdient tegen het vernietigende klimaatbeleid zoals windturbines en zonneparken. \
CO2 is een voedingsbron voor alles wat groeit en bloeit. Klimaatbeleid, dat draait om het terugdringen van de CO2-uitstoot, heeft dan ook bar weinig te maken met natuur of milieu. Niemand is tegen een groene leefomgeving of een goed milieu, ook de PVV niet. Waar de PVV wel tegen is, is zinloos, onbetaalbaar klimaatbeleid. \
De mens is verantwoordelijk voor slechts een paar procent van alle CO2 in de atmosfeer. Het is dan ook een illusie dat de mens het klimaat wezenlijk zou kunnen beïnvloeden. Het kleine Nederland is verantwoordelijk voor maar 0,35% van de totale wereldwijde CO2-uitstoot: verwaarloosbaar. Het Nederlandse klimaatbeleid leidt tot een mindere opwarming van de aarde van slechts 0,00007 graden: óók verwaarloosbaar. Maar toch is CO2 tot  de grote vijand  verklaard. De obsessieve, verregaande strijd tegen CO2- uitstoot vertoont inmiddels dictatoriale trekjes. Nederlanders die normaal hun leven willen leiden, wordt bij alles wat ze doen een klimaatschuldgevoel aangepraat en angst voor klimaatverandering aangejaagd. \
Klimaatbeleid kost vele, vele miljarden en stort huishoudens de financiële afgrond in. Klimaatbeleid is nergens goed voor, maar perkt onze vrije manier van leven des te ingrijpender in: we worden geregeerd door klimaathippies die willen dat we onze woningen voor vele tienduizenden euro s van het gas af halen, terwijl gas de schoonste fossiele brandstof is. Ze willen dat we in onbetaalbare elektrische auto s gaan rijden. Ze willen dat we minder vliegen, minder vlees eten. Het wordt ons allemaal opgedrongen, en dat moet stoppen. \
Tegelijkertijd worden ons land en onze Noordzee volgebouwd met subsidie-slurpende windturbines. Bomen worden verbrand in vervuilende biomassacentrales. Weilanden worden opgeofferd voor zonneparken. Ons prachtige landschap wordt kapotgemaakt onder het mom van een niet-bestaande  klimaatcrisis . Ook dat moet stoppen. \
De PVV zegt: wij laten ons niet de les lezen door wereldvreemde klimaatpredikers. Daarom maken we een einde aan de totaal geradicaliseerde klimaatgekte: de Klimaatwet, het Klimaatakkoord en alle onzinnige maatregelen gaan onmiddellijk de prullenbak in. Alle klimaat- en duurzaamheidssubsidies schaffen we direct af. Geen geld meer voor onzinnige linkse hobby s, maar méér geld in de portemonnee van onze mensen. \
Want door alle miljardensubsidies die aan de groene terreur worden verspild, gaat de energierekening omhoog en omhoog. Terwijl huishoudens in Duitsland geld toekrijgen als ze een gasaansluiting nemen, wordt gas in Nederland steeds duurder gemaakt. \
Nu al leven honderdduizenden huishoudens in energiearmoede: zij kunnen de energierekening nauwelijks tot niet meer betalen en zitten vaak letterlijk op de bank te rillen van de kou. Energie is een basisbehoefte, maar door de klimaatwaanzin is er een peperduur luxeproduct van gemaakt. \
De PVV kiest voor een fors lagere, betaalbare energierekening: we stoppen met de geldverslindende energietransitie en verlagen de energiebelasting. Woningen worden niet van het gas af gehaald. De afschaffing van de gasaansluitplicht draaien we terug, waardoor nieuwbouwwoningen weer een vertrouwde gasaansluiting kunnen krijgen - op het beste en meest betrouwbare gasnet ter wereld. Gas komt niet langer uit Groningen, maar halen we uit de bodem van de Noordzee en importeren we uit landen als Noorwegen, Engeland etc. – zoals nu al gebeurt. Onze kolencentrales, die tot de schoonste ter wereld behoren, blijven open. Ook worden er kerncentrales bijgebouwd die veiliger zijn dan ooit. Daarnaast zetten we in op thorium.", 4000);

	//TESTING STRCMP
	printf(CYAN);
	printf("\n\n> Testing Tijmen's ft_strcmp...\t\tstrcmp\tft_strcmp\n");
	STRCMP("Hello", "Hello");
	STRCMP("Hello", "");
	STRCMP("", "Hello");
	STRCMP("", "");
	STRCMP("Hell\200", "Hello");
	STRCMP("Hello", "Hell\200");
	STRCMP("Hell\200", "Hell\200");

	//TESTING WRITE
	printf(CYAN);
	printf("\n\n> Testing Tijmen's ft_write...\t\twrite\tft_write\n");
	WRITE("\"Writing this sentence to stdout...\"", 1, 36);
	int fd = open("test.txt", (O_RDWR | O_APPEND | O_CREAT), 0666);
	WRITE("\"Writing this sentence to an open file\"", fd, 39);
	close(fd);
	WRITE("\"Writing this sentence to a closed file\"", fd, 40);
	WRITE("\"Writing this sentence to a negative file descriptor\"", -1, 53);

	return(0);
}
