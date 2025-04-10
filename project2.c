#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h> // Use <windows.h> and Sleep(ms) on Windows

int main() {
    int wallet = 1000;
    int wager = 100;
    char pick[20];
    char again;

    srand(time(NULL));

    printf("🌟 Welcome to Mystic Clash: Tiger vs Dragon 🌟\n");
    printf("You have ₹%d to start with. Each clash costs ₹%d.\n\n", wallet, wager);

    do {
        printf("Who do you believe in? (Type 'Tiger' or 'Dragon'): ");
        scanf("%s", pick);

        // Normalize input
        for(int i = 0; pick[i]; i++) {
            if(pick[i] >= 'A' && pick[i] <= 'Z')
                pick[i] += 32;
        }

        if(wallet < wager) {
            printf("⚠️  Insufficient funds to continue!\n");
            break;
        }

        printf("🔮 The mystics are deciding...\n");
        sleep(2);

        int outcome = rand() % 2;
        char *champion = (outcome == 0) ? "dragon" : "tiger";

        if(strcmp(pick, champion) == 0) {
            wallet += wager;
            printf("✨ VICTORY! The %s prevails! You gain ₹%d\n", champion, wager);
        } else {
            wallet -= wager;
            printf("💥 Defeat! The %s wins. You lose ₹%d\n", champion, wager);
        }

        printf("💰 Remaining Balance: ₹%d\n", wallet);

        if(wallet >= wager) {
            printf("Clash again? (y/n): ");
            scanf(" %c", &again);
        } else {
            printf("🏁 Game over — funds exhausted!\n");
            break;
        }

    } while(again == 'y' || again == 'Y');

    printf("\nThanks for playing Mystic Clash! Final ₹%d left in your purse.\n", wallet);
    return 0;
}
