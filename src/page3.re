let component = ReasonReact.statelessComponent("Page3");

let make = _children => {
  ...component,
  render: _self =>
    <div className="Page3">
      <h1> (ReasonReact.stringToElement("Page3")) it's working</h1>
    </div>
};