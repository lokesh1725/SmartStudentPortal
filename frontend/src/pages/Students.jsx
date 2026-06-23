import { useState } from "react";
import studentData from "../data/students.json";

function Students() {

    const [students, setStudents] = useState(studentData);
    const [search, setSearch] = useState("");

    const [formData, setFormData] = useState({
        roll_no: "",
        name: "",
        department: "",
        year: "",
        email: ""
    });

    // Handle Input Changes
    const handleChange = (e) => {
        setFormData({
            ...formData,
            [e.target.name]: e.target.value
        });
    };

    // Add Student
    const addStudent = () => {

        const newStudent = {
            id: students.length + 1,
            ...formData
        };

        setStudents([...students, newStudent]);

        setFormData({
            roll_no: "",
            name: "",
            department: "",
            year: "",
            email: ""
        });
    };

    // Delete Student
    const deleteStudent = (id) => {

        const updatedStudents =
            students.filter(student => student.id !== id);

        setStudents(updatedStudents);
    };

    // Search Student
    const filteredStudents = students.filter(student =>
        student.name.toLowerCase().includes(search.toLowerCase()) ||
        student.roll_no.toLowerCase().includes(search.toLowerCase())
    );

    return (
        <div>

            <h1>Students</h1>

            {/* Search Box */}
            <input
                type="text"
                placeholder="Search by Name or Roll No"
                value={search}
                onChange={(e) => setSearch(e.target.value)}
            />

            {/* Add Student Form */}
            <div className="student-form">

                <input
                    name="roll_no"
                    placeholder="Roll No"
                    value={formData.roll_no}
                    onChange={handleChange}
                />

                <input
                    name="name"
                    placeholder="Name"
                    value={formData.name}
                    onChange={handleChange}
                />

                <input
                    name="department"
                    placeholder="Department"
                    value={formData.department}
                    onChange={handleChange}
                />

                <input
                    name="year"
                    placeholder="Year"
                    value={formData.year}
                    onChange={handleChange}
                />

                <input
                    name="email"
                    placeholder="Email"
                    value={formData.email}
                    onChange={handleChange}
                />

                <button onClick={addStudent}>
                    Add Student
                </button>

            </div>

            {/* Student Table */}
            <table className="student-table">

                <thead>
                    <tr>
                        <th>ID</th>
                        <th>Roll No</th>
                        <th>Name</th>
                        <th>Department</th>
                        <th>Year</th>
                        <th>Email</th>
                        <th>Action</th>
                    </tr>
                </thead>

                <tbody>

                    {filteredStudents.map(student => (

                        <tr key={student.id}>
                            <td>{student.id}</td>
                            <td>{student.roll_no}</td>
                            <td>{student.name}</td>
                            <td>{student.department}</td>
                            <td>{student.year}</td>
                            <td>{student.email}</td>

                            <td>
                                <button
                                    onClick={() => deleteStudent(student.id)}
                                >
                                    Delete
                                </button>
                            </td>
                        </tr>

                    ))}

                </tbody>

            </table>

        </div>
    );
}

export default Students;