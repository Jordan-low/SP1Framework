#include "Dialogue.h"

void Dialogue::Jerry(Console& g_Console)
{
    COORD c; COORD d;
    c.X = 5;
    c.Y = 26;
    d.X = 5;
    d.Y = 27;
	g_Console.writeToBuffer(c, "Jerry: Do not come near me you dirty street rat!", 0x0F, 100);
    g_Console.writeToBuffer(d, "       Can not believe one of them survived after it burnt down.", 0x0F, 100);
}

void Dialogue::Tom(Console& g_Console)
{
    COORD c; COORD d;
    c.X = 5;
    c.Y = 26;
    d.X = 5;
    d.Y = 27;
    g_Console.writeToBuffer(c, "Tom: Have you seen the protests recently? They are an awful", 0x0F, 100);
    g_Console.writeToBuffer(d, "     lot dangerous. Take some bread with you and stay away from them.", 0x0F, 100);
}

void Dialogue::Bobby(Console& g_Console)
{
    COORD c; 
    c.X = 5;
    c.Y = 26;
    g_Console.writeToBuffer(c, "Bobby: How dare you still have the cheek to come down here...", 0x0F, 100);
}

void Dialogue::Harry(Console& g_Console)
{
    COORD c; COORD d;
    c.X = 5;
    c.Y = 26;
    d.X = 5;
    d.Y = 27;
    g_Console.writeToBuffer(c, "Harry: I heard that there is an abandoned facility to the south.", 0x0F, 100);
    g_Console.writeToBuffer(d, "       Might be worth checking out.", 0x0F, 100);
}

void Dialogue::Sam(Console& g_Console)
{
    COORD c; COORD d; COORD e;
    c.X = 5;
    c.Y = 26;
    d.X = 5;
    d.Y = 27;
    e.X = 5;
    e.Y = 28;
    g_Console.writeToBuffer(c, "Sam: ouh it's you...here have some cake and be careful.", 0x0F, 100);
    g_Console.writeToBuffer(d, "     I really wanted you to stay with us but", 0x0F, 100);
    g_Console.writeToBuffer(e, "     we have very limited resources.", 0x0F, 100);
}

void Dialogue::Emmanuel(Console& g_Console)
{
    COORD c; COORD d;
    c.X = 5;
    c.Y = 26;
    d.X = 5;
    d.Y = 27;
    g_Console.writeToBuffer(c, "Emmanuel: I saw you running out of the burning orphanage, are", 0x0F, 100);
    g_Console.writeToBuffer(d, "          you hurt? I got some medical supplies if you need some", 0x0F, 100);
}

void Dialogue::Charles(Console& g_Console)
{
    COORD c; COORD d;
    c.X = 5;
    c.Y = 26;
    d.X = 5;
    d.Y = 27;
    g_Console.writeToBuffer(c, "Charles: How could someone of this age be running around", 0x0F, 100);
    g_Console.writeToBuffer(d, "         without an adult around, where are your parents?", 0x0F, 100);
}
