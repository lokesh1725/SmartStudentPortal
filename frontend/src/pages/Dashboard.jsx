import bharathiyarImage from "../assets/bharathiyar.jpg";

function Dashboard() {
  return (
    <div>

      <h1>Dashboard</h1>

      {/* Dashboard Cards */}

      <div className="cards">

        <div className="card">
          <h2>61</h2>
          <p>Total Students</p>
        </div>

        <div className="card">
          <h2>85%</h2>
          <p>Attendance</p>
        </div>

        <div className="card">
          <h2>78%</h2>
          <p>Average Marks</p>
        </div>

      </div>

      {/* College Section */}

      <div className="college-section">

        <img
          src={bharathiyarImage}
          alt="Bharathiyar"
          className="college-image"
        />

        <h2> Tamizhan College of Engineering and Technology </h2>

        <p>
          Rajiv Gandhi Salai, Old Mamallapuram Road,
          Chennai - 600119
        </p>

        <p>
          <strong>Welcome to Smart Student Portal</strong>
        </p>

      </div>

    </div>
  );
}

export default Dashboard;