module ComposableMap = {
  [@bs.deriving abstract]
  type jsProps = {style: ReactDOMRe.style};

  [@bs.module "react-simple-maps"]
  external jsComponent : ReasonReact.reactClass = "ComposableMap";

  let make = (~style, children: array(ReasonReact.reactElement)) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=jsComponent,
      ~props=jsProps(~style),
      children,
    );
};

module ZoomableGroup = {
  [@bs.module "react-simple-maps"]
  external jsComponent : ReasonReact.reactClass = "ZoomableGroup";

  let make = (children: array(ReasonReact.reactElement)) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=jsComponent,
      ~props=Js.Dict.empty,
      children,
    );
};

type geography;
type projection;

module Geographies = {
  [@bs.deriving abstract]
  type jsProps = {geography: string};

  [@bs.module "react-simple-maps"]
  external jsComponent : ReasonReact.reactClass = "Geographies";

  let make =
      (
        ~geography,
        children:
          (. array(geography), projection) => array(ReasonReact.reactElement),
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=jsComponent,
      ~props=jsProps(~geography),
      children,
    );
};

module Geography = {
  [@bs.deriving abstract]
  type jsProps = {
    geography,
    projection,
  };

  [@bs.module "react-simple-maps"]
  external jsComponent : ReasonReact.reactClass = "Geography";

  let make = (~geography, ~projection, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=jsComponent,
      ~props=jsProps(~geography, ~projection),
      children,
    );
};

module Markers = {
  [@bs.module "react-simple-maps"]
  external jsComponent : ReasonReact.reactClass = "Markers";

  let make = (children: array(ReasonReact.reactElement)) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=jsComponent,
      ~props=Js.Dict.empty,
      children,
    );
};

module Marker = {
  [@bs.deriving abstract]
  type mark = {coordinates: (float, float)};

  [@bs.deriving abstract]
  type jsProps = {marker: mark};

  [@bs.module "react-simple-maps"]
  external jsComponent : ReasonReact.reactClass = "Marker";

  let make = (~marker, children: array(ReasonReact.reactElement)) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=jsComponent,
      ~props=jsProps(~marker),
      children,
    );
};
