# Artificial Intelligence

New AI Models are able to generate text and images that are interesting and make sense, some of the images can look almost realistic and can produce entire news stories. It is becoming harder to discern the real from the artificially generated as the technology progresses.

**Prompt Engineering** is a term used to describe the act of giving AI a good system prompt that teaches it how to behave in the way you want it to, in the example of Harvard's DDB it is geared towards focusing on Computer Science and specific aspects of it.

The above is known as a *system prompt* whereas a *user prompt* is the actualy question the end user asks so the AI will take into consideration it's own knowledge while following the guidelines set by the *system prompt* and attempt to answer the *user prompt*.

## Human Intuition

The way to build an AI model is to attempt to convert what we consider the intuitive route to take, for example like playing the breakout game you understand to move the paddle towards the ball so you don't lose the game.

``` mermaid
graph TD
    A[Start] --> B{Is ball left of paddle?}
    B -- Yes --> C[Move left]
    B -- No --> D{Is ball right of paddle?}
    D -- Yes --> E[Move right]
    D -- No --> F[Stay still]
```

