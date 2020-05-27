#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int words(string b);
int sentences(string c);

    int main(void)
{
    int countL = 0;
    string text = get_string("Text: ");

    for (int i = 0; i < strlen(text) ; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >='A' && text[i] <= 'Z'))
        {
            countL++;
        }

    }
       // printf("%i letter(s)\n", countL); //prints out the number of letters the user inputs.

    int num_words = words(text);
    //printf("%i word(s)\n", num_words); //prints out the number of words user inputs.

    int num_sents = sentences(text);
   // printf("%i sentence(s)\n", num_sents);

    float letters = countL;
    float words = num_words;
    float sents = num_sents;

    float L = (float) (letters/words) *100 ; // must include (float) so that the division will produce a float number
    float S = (float) (sents/words) *100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    int round_index = round(index);

    if(index > 16)
    {
        printf("Grade 16+\n");
    }
    else if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", round_index);
    }

}

    int words(string b)
{
    int countW = 0;

    for(int i = 0; b[i] != '\0'; i++) //This calculates the string until it reaches the end string  \0 .
    {

            if(b[i-1] == ' ' || i == 0) //This makes sure that the space before and after the string are either a space,
            {                            //or there is nothing
                countW++;                //before the string to calculate a "word"
            }


    }

    return countW;
}

    int sentences(string c)
    {
        int countS = 0;

        for (int i = 0; c[i] != '\0'; i++)
        {
                if(c[i] == '.' || c[i] == '!' || c[i] == '?') //if there is punctuation, calculate that as a sentence.
                {
                    countS++;
                }
        }
    return countS;
    }
