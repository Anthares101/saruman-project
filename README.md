# Saruman project

This project is a base project for all GAS related test tasks. Should make the process of learning GAS easier for BFME Reforged newcomers

## Prerequisites

You will need:
- Visual Studio code configured for Unreal development
- Last Unreal Engine 4 version installed

## How to open the project

Follow this steps:

1. Clone the repository
2. Go to the folder and right click in `Saruman.uproject`
3. Click on `Generate Visual Studio project files` and wait for it to finish
4. Now you can double click on `Saruman.uproject` and Unreal will ask to rebuild the module, do it and wait for it to finish

After all this steps the project should open for you. Maybe the editor report some errors about the lighting system, just click on the Unreal editor `Render` button (Maybe the editor ask you for network access, allow it, it is needed for this process).

## Additional information

The `SarumanPlayerController` already has the F key configured to execute an ability. No abilities are shipped with this project, so at first it will simply do nothing until an ability is created and configured to use.
