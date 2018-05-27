open Belt;

type action =
  | Receive(array(Fetcher.data));

type state =
  | Loading
  | Fetched(array(Fetcher.data));

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => Loading,
  reducer: (action, _state) =>
    switch (action) {
    | Receive(locations) => Update(Fetched(locations))
    },
  didMount: self => {
    let addLocationUrl = "https://immense-river-25513.herokuapp.com/add-location";
    let locationsUrl = "https://immense-river-25513.herokuapp.com/locations";

    Fetcher.fetchPost(~url=addLocationUrl, ~body="jguyon");

    Fetcher.fetchGet(~url=locationsUrl, ~cb=locations =>
      self.send(Receive(locations))
    );
    let id =
      Js.Global.setInterval(
        () =>
          Fetcher.fetchGet(~url=locationsUrl, ~cb=locations =>
            self.send(Receive(locations))
          ),
        30000,
      );
    self.onUnmount(() => Js.Global.clearInterval(id));
  },
  render: self =>
    ReactSimpleMaps.(
      <div
        style=(
          ReactDOMRe.Style.make(
            ~width="100%",
            ~maxWidth="1080px",
            ~margin="0 auto",
            (),
          )
        )>
        <ComposableMap
          style=(ReactDOMRe.Style.make(~width="100%", ~height="auto", ()))>
          <ZoomableGroup>
            <Geographies geography="world-50m.json">
              ...(
                   (. geographies, projection) =>
                     Array.mapWithIndex(geographies, (i, geography) =>
                       <Geography
                         key=(i |. string_of_int)
                         geography
                         projection
                       />
                     )
                 )
            </Geographies>
            <Markers>
              ...(
                   switch (self.state) {
                   | Loading => [|ReasonReact.null|]
                   | Fetched(locations) =>
                     Array.map(locations, data =>
                       <Marker
                         key=(data |. Fetcher.username)
                         marker=(
                           Marker.mark(
                             ~coordinates=
                               data |. Fetcher.location |. (snd, fst),
                           )
                         )>
                         <circle
                           cx="0"
                           cy="0"
                           r="3"
                           stroke="#fff"
                           strokeWidth="1"
                           fill="#f00"
                         />
                       </Marker>
                     )
                   }
                 )
            </Markers>
          </ZoomableGroup>
        </ComposableMap>
      </div>
    ),
};
