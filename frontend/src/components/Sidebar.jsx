import { Link } from "react-router-dom";

function Sidebar() {
  return (
    <div className="sidebar">
      <ul>
        <li>
          <Link to="/">Dashboard</Link>
        </li>

        <li>
          <Link to="/students">Students</Link>
        </li>
      </ul>
    </div>
  );
}

export default Sidebar;