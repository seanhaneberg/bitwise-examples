#include <stdio.h>

typedef enum _SessionOptions
{
    NONE = 0x0,                    // 0000
    LEADERBOARD_SUPPORT = 0x1,     // 0001
    MULTIPLAYER_SUPPORT = 0x2,     // 0010
    ONLINE_PRESENCE_SUPPORT = 0x4, // 0100
    CHAT_SUPPORT = 0x8,            // 1000
    ONLINE_DEFAULTS =              // 0111
    LEADERBOARD_SUPPORT |
    MULTIPLAYER_SUPPORT |
    ONLINE_PRESENCE_SUPPORT

} SessionOptions;

void startGameSession(char *name, int sessionOptions)
{
    printf("\nSession %s started with the following options:\n", name);
    if (sessionOptions & LEADERBOARD_SUPPORT)
    {
        printf("\tLeaderboard Support\n");
    }

    if (sessionOptions & MULTIPLAYER_SUPPORT)
    {
        printf("\tMultiplayer Support\n");
    }

    if (sessionOptions & ONLINE_PRESENCE_SUPPORT)
    {
        printf("\tOnline Presence Support\n");
    }

    if (sessionOptions & CHAT_SUPPORT)
    {
        printf("\tOnline Chat Support\n");
    }
}

int main()
{
    startGameSession("Online Defaults", ONLINE_DEFAULTS);
    startGameSession("Online Defaults with Chat", ONLINE_DEFAULTS | CHAT_SUPPORT);
    startGameSession("Multiplayer Only", MULTIPLAYER_SUPPORT);
    startGameSession("Multiplayer and Leaderboards",
                     MULTIPLAYER_SUPPORT | LEADERBOARD_SUPPORT);

    return 0;
}
