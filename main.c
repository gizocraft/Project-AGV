#include <avr/io.h>
#ifndef F_CPU
#define F_CPU 16000000ul
#endif
#include <avr/interrupt.h>
#include <util/delay.h>
#include "h_bridge.h"
#include "h_bridge.h_2.h"
#include "h_bridge.h_3.h"
#define Knop1 PF1
#define Knop2 PF2
#define Knop3 PF3
#define Knop4 PF4
#define Knop5 PF5
#define Knop6 PF6


void init(void)
{
    init_h_bridge(); //dit moet hbrug 2 zijn NOTITTIE
    init_h_bridge_1();
    init_h_bridge_2();



    DDRF  &= ~(1<<Knop1);
    DDRF  &= ~(1<<Knop2);
    DDRF  &= ~(1<<Knop3);
    DDRF  &= ~(1<<Knop4);
    DDRF  &= ~(1<<Knop5);
    DDRF  &= ~(1<<Knop6);

    PORTF |= (1<< Knop1);
    PORTF |= (1<< Knop2);
    PORTF |= (1<< Knop3);
    PORTF |= (1<< Knop4);
    PORTF |= (1<< Knop5);
    PORTF |= (1<< Knop6);
}


/*
int Knop_1_ingedrukt (void)
{
int knop;
    if (!(PINA & (1 << Knop1)))
    {
        knop = 1;
    }
    else
    {
        knop = 0;
    }
    return(knop);

}

int Knop_2_ingedrukt (void)
{
int knop;
    if (!(PINA & (1 << Knop2)))
    {
        knop = 1;
    }
    else
    {
        knop = 0;
    }
    return(knop);

}

int Knop_3_ingedrukt (void)
{
int knop;
    if (!(PINA & (1 << Knop3)))
    {
        knop = 1;
    }
    else
    {
        knop = 0;
    }
    return(knop);

}

int Knop_4_ingedrukt (void)
{
int knop;
    if (!(PINA & (1 << Knop4)))
    {
        knop = 1;
    }
    else
    {
        knop = 0;
    }
    return(knop);

}

int Knop_5_ingedrukt (void)
{
int knop;
    if (!(PINA & (1 << Knop5)))
    {
        knop = 1;
    }
    else
    {
        knop = 0;
    }
    return(knop);

}

int Knop_6_ingedrukt (void)
{
int knop;
    if (!(PINA & (1 << Knop6)))
    {
        knop = 1;
    }
    else
    {
        knop = 0;
    }
    return(knop);

}
*/

int main(void)
{
    init();

    int i = 0;
    int j = 0;
    int k = 0;
    int veiligheid = 0;
    int veiligheid_2 = 0;
    int veiligheid_3 = 0;
    /* int Knop_1
     int Knop_2
     int Knop_3
     int Knop_4
     int Knop_5
     int Knop_6*/

    while (1)
    {



        if (!(PINF & (1 << Knop1)))
        {
            if (!(PINF & (1 << Knop2)))
            {
                veiligheid = 1;
            }
        }
        else
        {veiligheid = 0;
        h_bridge_set_percentage_1 (i);
        i = 0;

        }

        if (!(PINF & (1 << Knop3)))
        {
            if (!(PINF & (1 << Knop4)))
            {
                veiligheid_2 = 1;
            }
        }
        else
        {veiligheid_2 = 0;
        j = 0;
        h_bridge_set_percentage_2 (j);
        }


        if (!(PINF & (1 << Knop5)))
        {


            if (!(PINF & (1 << Knop6)))
            {

                veiligheid_3 = 1;
            }

        }
        else
        {veiligheid_3 = 0;
        k = 0;
        h_bridge_set_percentage_3 (k);
        }




        if (veiligheid == 1)
        {
            h_bridge_set_percentage_1 (0);
        }

        else
        {



            if (!(PINF & (1 << Knop1)))
            {
                i = 100;
                h_bridge_set_percentage_1 (i);
            }

            if (!(PINF & (1 << Knop2)))
            {
                i = -100;
                h_bridge_set_percentage_1 (i);
            }
            else
            {
                i = 0;

            }

        }


        if (veiligheid_2 == 1)
        {
            h_bridge_set_percentage_2 (0);
        }

        else
        {



            if (!(PINF & (1 << Knop3)))
            {
                j = 100;
                h_bridge_set_percentage_2 (j);
            }

            if (!(PINF & (1 << Knop4)))
            {
                j = -100;
                h_bridge_set_percentage_2 (j);
            }
            else
            {
                j = 0;

            }

        }



        if (veiligheid_3 == 1)
        {
            h_bridge_set_percentage_3 (0);
        }

        else
        {



            if (!(PINF & (1 << Knop5)))
            {
                k = 99;
                h_bridge_set_percentage_3 (k);
            }

            if (!(PINF & (1 << Knop6)))
            {
                k = -100;
                h_bridge_set_percentage_3 (k);
            }
            else
            {
                h_bridge_set_percentage_3 (0);
            }

        }






        /*
                if (veiligheid == 1)
                {

                    h_bridge_set_percentage_1 (0);
                }
                else
                {
                    if (Knop_1_ingedrukt () | Knop_2_ingedrukt ())
                    {
                        if (!(PINA & (1<< Knop1)))
                            {
                                j = 100;
                                h_bridge_set_percentage_1 (j);
                            }
                            if (!(PINA & (1<< Knop2)))
                                {
                                    j = -100;
                                    h_bridge_set_percentage_1 (j);
                                }
                    }
                    else
                    {
                        j = 0;
                    }
                }








                    if (veiligheid_2 == 1)
                {

                    h_bridge_set_percentage_2 (0);
                }
                else
                {
                    if (Knop_3_ingedrukt () | Knop_4_ingedrukt ())
                    {
                        if (!(PINA & (1<< Knop3)))
                            {
                                k = 100;
                                h_bridge_set_percentage_2 (k);
                            }
                            if (!(PINA & (1<< Knop4)))
                                {
                                    k = -100;
                                    h_bridge_set_percentage_2 (k);
                                }
                    }
                    else
                    {
                        k = 0;
                    }
                }


                if (veiligheid_3 == 1)
                {

                    h_bridge_set_percentage_3 (0);
                }
                else
                {
                    if (Knop_5_ingedrukt () | Knop_6_ingedrukt ())
                    {
                        if (!(PINA & (1<< Knop5)))
                            {
                                i = 100;
                                h_bridge_set_percentage_3 (i);
                            }
                            if (!(PINA & (1<< Knop6)))
                                {
                                    i = -100;
                                    h_bridge_set_percentage_3 (i);
                                }
                    }
                    else
                    {
                        i = 0;
                    }
                }
                */









    }

    return 0;
}
/*

while (1)
{
    for (int i = 0; i<100; i++)
    {
        h_bridge_set_percentage_1(i);
        h_bridge_set_percentage_2(i);
        h_bridge_set_percentage_3(i);
    }
    _delay_ms (3000);

    for (int i = 0; i>-100; i--)
    {
        h_bridge_set_percentage_1(i);
        h_bridge_set_percentage_2(i);
        h_bridge_set_percentage_3(i);
    }
    _delay_ms (3000);
}


return 0;
}*/
