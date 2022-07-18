# EToD [![License](https://img.shields.io/github/license/SlaterVanS/EToD.svg)](https://github.com/SlaterVanS/EToD/blob/main/LICENSE)

![EToD](/Sandbox/assets/textures/EToD_Engine.png?raw=true "EToD")

EToD is primarily an early-stage interactive application and rendering engine for Windows. Currently not much is implemented. We hope to improve our engine and make it more powerful through more version iterations in the future. At present, our studio has uploaded our latest project files to this repository, found at [SlaterVanS.com/EToD](https://github.com/SlaterVanS/EToD). 

***

## Getting Started
Visual Studio 2017 or 2019 is recommended, EToD Engine is officially untested on other development environments whilst we focus on a Windows build.

You can clone the repository to a local destination using git:

`git clone --recursive https://github.com/SlaterVanS/EToD`.

Make sure that you do a `--recursive` clone to fetch all of the submodules!

***

## The Plan
The plan for EToD Engine is two-fold: to create a powerful 3D engine, but also to serve as an education tool for small team or college student development. Because of this the development inside this repository is rather slow, since everything has to be ensure that the function can be more perfect and can be used normally. There is a much more advanced version of the engine in a private repository called `EToD-dev`, accessible to studio internal developer on [SlaterVanS Studio](https://www.slatervans.com/etod). The plan for this project is to mostly take already implemented code from the `EToD-dev` repository and integrate it into this one, we will test more experimental functions in this repository.

### Main features to come:
- Fast 2D rendering (UI, particles, sprites, etc.)
- High-fidelity Physically-Based 3D rendering (this will be expanded later, 2D to come first)
- Support for Mac, Linux, Android and iOS
    - Native rendering API support (DirectX, Vulkan, Metal)
- Fully featured viewer and editor applications
- Fully scripted interaction and behavior
- Integrated 3rd party 2D and 3D physics engine
- Procedural terrain and world generation
- Artificial Intelligence
- Audio system

***

## Short term goals :
*Note: this is subject to change at any time! Follow the roadmap over at [slatervans.com/roadmap](http://www.slatervans.com).*

By the end 2022, we want to make a game using the EToD game engine. Not like the time I made a game in one hour using the engine, but this time by using the proper tools that would be required to make a game with EToD. This means we need to add a full 2D workflow:

- Design the game scene by using EToD_Editor, the EToD editor,
- Test the game inside EToD_Edito, including the ability to save/load the created game,
- Load and play the game inside Sandbox.

We want everyone to be able to play the game on all desktop platforms (Windows, Mac and Linux). When this is implemented, another attempt at the "Creating a game in one hour using EToD" will be made to see how far the engine has become.

***

EToD Engine

Easy To Development.

Powered by SlaterVanS Studio.
