'use strict';

module.exports = {
  load () {
    // execute when package loaded
    console.log("RemoteConfig package loaded");
  },

  unload () {
    // execute when package unloaded
    console.log("RemoteConfig package unloaded");
  },

  // register your ipc messages here
  messages: {
    'say-hello' () {
      console.log('Hello World!');
    }
  },
};