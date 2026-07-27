const userDiv = document.getElementById("users");


const worker = new Worker("worker.js");


// send request to worker
worker.postMessage("fetch users");



worker.onmessage = function(event) {


    if(event.data.error) {

        userDiv.innerHTML = event.data.error;
        return;

    }


    const users = event.data.users;


    userDiv.innerHTML = "";


    users.forEach(user => {


        const p = document.createElement("p");


        const status = user.active 
            ? "Active" 
            : "Inactive";


        p.textContent = `${user.name} - ${status}`;


        userDiv.appendChild(p);


    });

};



worker.onerror = function() {

    userDiv.innerHTML = "Something went wrong";

};