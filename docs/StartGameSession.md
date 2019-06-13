# Start Game Session

Consider the following enum and function signature:

```c
typedef enum _SessionOptions
{
    NONE = 0x0,                     // 0000
    LEADERBOARD_SUPPORT = 0x1,      // 0001
    MULTIPLAYER_SUPPORT = 0x2,      // 0010
    ONLINE_PRESENCE_SUPPORT = 0x4,  // 0100
    CHAT_SUPPORT = 0x8,             // 1000
    ONLINE_DEFAULTS =               // 0111
        LEADERBOARD_SUPPORT |
        MULTIPLAYER_SUPPORT |
        ONLINE_PRESENCE_SUPPORT

} SessionOptions;

void startGameSession(char * name, int sessionOptions);
```

If you're developing a video game, you may need to call a function like this to
tell the platform that you'd like to create a game session with certain
properties.

Consumers of this API can use bitwise operators to assign a value to the
`sessionOptions` argument.

See the [StartGameSession](./StartGameSession.md) example for more details.

## Can expose different combinations of flags

Note how ONLINE_DEFAULTS is a bitwise combination of the relevant values.
Useful bitwise combinations can be exposed to API consumers or used in other logic.

## Using the & operator and masking to read bits

Consider how this implementation of `startGameSession` evaluates `sessionOptions`:

```c
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
```

Notice how the `&` operator is used to test if certain bits are "turned on."
