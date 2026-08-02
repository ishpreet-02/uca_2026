const users = [
    { name: "Ishpreet", age: 25 },
    { name: "Rahul", age: 30 },
    { name: "Karan", age: 35 },
];

const fields = [
    "First Name",
    "Last Name",
    "Email"
];

function generateForm() {
    return `
        <form>
            ${fields.map(field => `
                <label>${field}</label>
                <input type="text"><br><br>
            `).join("")}
        </form>
    `;
}

function generateTable() {
    return `
    <table>
        ${users.map(user => `
            <tr>
                <td>${user.name}</td>
                <td>${user.age}</td>
            </tr>
            `).join("")}
    </table>
    `;

}

document.getElementById("table-container").innerHTML = generateTable();
document.getElementById("form-container").innerHTML = generateForm();