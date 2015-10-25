ofxKUI
======

Introduction
------------
ofxKUI helps you to control your openFrameworks app with your keyboard.
It is composed of different modes that you can activate by pressing keys.
The interface is inspired by Vim.

Modes
-----
ofxKUI is composed of different modes that let you achieve different kinds of interactions with your app. 
The different modes are explained below. 
The character between **[]** represents the key you need to press to activate the mode when in normal mode. 
Special keys are represented between diples like this: `<Esc>` represents the `Escape` key. 

**normal mode [`<Esc>`]**

In this mode you can access all the other modes. It is kind of a 'base mode'.

**camera mode [`c`]**

This mode lets you control a camera with your keyboard, provided that you set a camera using the `setCamera` method. 
When in camera mode, you can use keys to move or rotate the camera.
See the `example-camera` example for a demonstration and more information.

**command mode [`d`]**

-- TODO --
This mode lets you enter commands. It is essentially used to set parameter values.

**interactive mode [`i`]**

-- TODO --
This mode lets you change parameters interactively.

License
-------
[MIT License](https://en.wikipedia.org/wiki/MIT_License). See `license.md` for a copy of the MIT license.

Installation
------------
Just drop the folder into the `openFrameworks/addons/` folder.

Dependencies
------------
No dependencies other than the ofxGUI core addon.

Troubleshooting
---------------

The command bar should normally be at the bottom of your window. If it's not, check that your window height is inferior to your screen height because sometimes the bottom of your window can be hidden by your taskbar.

`<Esc>` for quiting the app is disabled since it is used to escape command mode.


Compatibility
------------
Works with oF 0.9.0. Tested with Linux.

Known issues
------------
Rotating the camera resets the camera lookAt point to (0, 0, 0).

The `Hack` font needs to be included in the app `bin/data` directory.
See the examples.

Contributing
------------
Feel like contributing? You're most welcome!

<!-- Version history
------------
It make sense to include a version history here (newest releases first), describing new features and changes to the addon. Use [git tags](http://learn.github.com/p/tagging.html) to mark release points in your repo, too!

### Version 0.1 (Date):
Describe relevant changes etc.

 -->
