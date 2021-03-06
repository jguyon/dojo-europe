// Generated by BUCKLESCRIPT VERSION 3.1.4, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Belt_Array = require("bs-platform/lib/js/belt_Array.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Fetcher$MyProjectName = require("./Fetcher.bs.js");
var ReactSimpleMaps$MyProjectName = require("./ReactSimpleMaps.bs.js");

var component = ReasonReact.reducerComponent("App");

function make() {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */(function (self) {
              var locationsUrl = "https://immense-river-25513.herokuapp.com/locations";
              Fetcher$MyProjectName.fetchPost("https://immense-river-25513.herokuapp.com/add-location", "jguyon");
              Fetcher$MyProjectName.fetchGet(locationsUrl, (function (locations) {
                      return Curry._1(self[/* send */3], /* Receive */[locations]);
                    }));
              var id = setInterval((function () {
                      return Fetcher$MyProjectName.fetchGet(locationsUrl, (function (locations) {
                                    return Curry._1(self[/* send */3], /* Receive */[locations]);
                                  }));
                    }), 30000);
              return Curry._1(self[/* onUnmount */4], (function () {
                            clearInterval(id);
                            return /* () */0;
                          }));
            }),
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (self) {
              var match = self[/* state */1];
              return React.createElement("div", {
                          style: {
                            margin: "0 auto",
                            maxWidth: "1080px",
                            width: "100%"
                          }
                        }, ReasonReact.element(/* None */0, /* None */0, ReactSimpleMaps$MyProjectName.ComposableMap[/* make */0]({
                                  height: "auto",
                                  width: "100%"
                                }, /* array */[ReasonReact.element(/* None */0, /* None */0, ReactSimpleMaps$MyProjectName.ZoomableGroup[/* make */0](/* array */[
                                            ReasonReact.element(/* None */0, /* None */0, ReactSimpleMaps$MyProjectName.Geographies[/* make */0]("world-50m.json", (function (geographies, projection) {
                                                        return Belt_Array.mapWithIndex(geographies, (function (i, geography) {
                                                                      return ReasonReact.element(/* Some */[String(i)], /* None */0, ReactSimpleMaps$MyProjectName.Geography[/* make */0](geography, projection, /* array */[]));
                                                                    }));
                                                      }))),
                                            ReasonReact.element(/* None */0, /* None */0, ReactSimpleMaps$MyProjectName.Markers[/* make */0](match ? Belt_Array.map(match[0], (function (data) {
                                                              var __ocaml_internal_obj = data.location;
                                                              return ReasonReact.element(/* Some */[data.username], /* None */0, ReactSimpleMaps$MyProjectName.Marker[/* make */0]({
                                                                              coordinates: /* tuple */[
                                                                                __ocaml_internal_obj[1],
                                                                                __ocaml_internal_obj[0]
                                                                              ]
                                                                            }, /* array */[React.createElement("circle", {
                                                                                    cx: "0",
                                                                                    cy: "0",
                                                                                    fill: "#f00",
                                                                                    r: "3",
                                                                                    stroke: "#fff",
                                                                                    strokeWidth: "1"
                                                                                  })]));
                                                            })) : /* array */[null]))
                                          ]))])));
            }),
          /* initialState */(function () {
              return /* Loading */0;
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, _) {
              return /* Update */Block.__(0, [/* Fetched */[action[0]]]);
            }),
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

exports.component = component;
exports.make = make;
/* component Not a pure module */
