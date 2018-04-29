[%bs.raw {|require('./app.css')|}];

type route =
| Home
| Page1
| Page2
| Page3;

type routeWithTitle = (route, string);

type user = {
  name: string,
  email: string
};

type nav = {isOpen: bool};

type action =
  | Navigate(routeWithTitle)
  | ToggleMenu(bool);

type state = {
  routeWithTitle,
  user,
  nav
};

subscriptions: self => [
  Sub(
    () =>
      ReasonReact.Router.watchUrl(url =>
        switch url.path {
        | ["page1"] => self.send(Navigate((Page1, "Page1")))
        | ["page2"] => self.send(Navigate((Page2, "Page2")))
        | ["page3"] => self.send(Navigate((Page3, "Page3")))
        | _ => self.send(Navigate((Home, "Home")))
        }
      ),
    ReasonReact.Router.unwatchUrl
  )
],

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {
    routeWithTitle: (Home, "Home"),
    user: {
      name: "Person Name",
      email: "person@email.com"
    },
    nav: {
      isOpen: false
    }
  },
  reducer: (action, state) =>
    switch action {
    | Navigate(_routeWithTitle) => ReasonReact.NoUpdate
    | ToggleMenu(isOpen) =>
      ReasonReact.Update({
        ...state,
        nav: {
          isOpen: isOpen
        }
      })
    },
  render: _self => <div className="App" />
};