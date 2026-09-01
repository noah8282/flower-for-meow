#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/* ANSI colors for a nicer-looking flower */
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define RESET   "\033[0m"

/* Function to get a random love message */
const char* get_message(void) {
    const char *messages[] = {
        "I love you Meow!",
        "You mean the world to me.",
        "My love grows for you every day. just like this flower",
        "You are my favorite person.",
        "I am so lucky to have you.",
        "Just a little reminder that I adore you.",
        "You make everything better.",
        "Monu loves you meow",
        "Thanks for burning yourself and giving me light, you are my candle.",
        "You are my sunshine on cloudy days.",
        "Every moment with you feels magical.",
        "You make my heart smile.",
        "I still get excited every time I see you.",
        "You are the best part of my day.",
        "My favorite place is next to you.",
        "You make ordinary moments special.",
        "I love your cute little smile.",
        "You are my happy thought.",
        "Even stars look dull beside you.",
        "You are the reason I believe in love.",
        "I could listen to your voice forever.",
        "You are my comfort person.",
        "Loving you is the easiest thing ever.",
        "You are sweeter than my favorite dessert.",
        "I hope you know how special you are to me.",
        "You make my world brighter.",
        "You are my favorite notification.",
        "No matter what happens, I'll choose you.",
        "You are the cutest chapter of my life.",
        "If hugs could talk, mine would say 'I love you.'"
    };

    int num_messages = sizeof(messages) / sizeof(messages[0]);
    int random_index = rand() % num_messages;
    return messages[random_index];
}

int main(void) {
    srand((unsigned int)time(NULL));

    const char* chosen_message = get_message();

    /* Six-frame growth animation: seed -> sprout -> stem -> bud -> opening -> full bloom */
    const char *frames[] = {

        /* Frame 1: a seed resting in the soil */
        "\n\n\n\n\n"
        "        " YELLOW "." RESET "\n"
        "     " GREEN "~~~~~~~~~~~" RESET "\n",

        /* Frame 2: a tiny sprout pokes through */
        "\n\n\n\n"
        "        " GREEN "!" RESET "\n"
        "        " GREEN "|" RESET "\n"
        "     " GREEN "~~~~~~~~~~~" RESET "\n",

        /* Frame 3: the stem grows, first leaves unfurl */
        "\n\n\n"
        "        " GREEN "|" RESET "\n"
        "      " GREEN "\\ |" RESET "\n"
        "        " GREEN "|" RESET " " GREEN "/" RESET "\n"
        "        " GREEN "|" RESET "\n"
        "     " GREEN "~~~~~~~~~~~" RESET "\n",

        /* Frame 4: a bud forms at the top */
        "\n\n"
        "       " GREEN "(" YELLOW "o" GREEN ")" RESET "\n"
        "        " GREEN "|" RESET "\n"
        "      " GREEN "\\_|" RESET "\n"
        "        " GREEN "|" RESET " " GREEN "/" RESET "\n"
        "        " GREEN "|" RESET "\n"
        "     " GREEN "~~~~~~~~~~~" RESET "\n",

        /* Frame 5: the bud starts to open */
        "\n"
        "      " MAGENTA "." RESET GREEN "(" RESET YELLOW "@" RESET GREEN ")" RESET MAGENTA "." RESET "\n"
        "       " GREEN "\\_|_/" RESET "\n"
        "         " GREEN "|" RESET "\n"
        "       " GREEN "\\_|" RESET "\n"
        "         " GREEN "|" RESET " " GREEN "/" RESET "\n"
        "         " GREEN "|" RESET "\n"
        "      " GREEN "~~~~~~~~~~~" RESET "\n",

        /* Frame 6: full bloom, in color, with leaves */
        "    " MAGENTA "\\" RESET BOLD RED " _(_)_ " RESET MAGENTA "/" RESET "\n"
        "   " MAGENTA "-" RESET BOLD RED "(_)" YELLOW "@" RED "(_)" RESET MAGENTA "-" RESET "\n"
        "    " MAGENTA "/" RESET BOLD RED " (_)‾ " RESET MAGENTA "\\" RESET "\n"
        "        " GREEN "|" RESET "\n"
        "      " GREEN "\\_|_/" RESET "\n"
        "        " GREEN "|" RESET "\n"
        "      " GREEN "\\_|" RESET "\n"
        "   " GREEN "\\_" RESET GREEN "|" RESET GREEN "_/" RESET "\n"
        "        " GREEN "|" RESET "\n"
        "     " GREEN "~~~~~~~~~~~" RESET "\n"
    };

    int num_frames = sizeof(frames) / sizeof(frames[0]);

    for (int i = 0; i < num_frames; i++) {
        system("clear");

        printf("\n  " BOLD CYAN "***" RESET " %s " BOLD CYAN "***" RESET "\n", chosen_message);
        printf("%s", frames[i]);

        fflush(stdout);

        /* Hold the final bloom a little longer than the growth frames */
        if (i == num_frames - 1) {
            usleep(2000000); /* 2.0 seconds on the finished flower */
        } else {
            usleep(700000);  /* 0.7 seconds per growth frame */
        }
    }

    printf("\n");
    return 0;
}