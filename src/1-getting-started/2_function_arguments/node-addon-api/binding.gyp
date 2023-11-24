{
  "targets": [
    {
      "target_name": "addon",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [ "addon.cc" ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    },
     {
      "target_name": "action_after_build",
      "type": "none",
      "dependencies": [ "addon" ],
      "copies": [
          {
            "files": [ "./build/Release/addon.node" ],
            "destination": "../../../../build"
          }
      ]
    }
  ]
}