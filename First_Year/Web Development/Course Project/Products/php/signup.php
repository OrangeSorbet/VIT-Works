<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Collect and sanitize form data
    $fullName = htmlspecialchars($_POST['full_name']);
    $email = htmlspecialchars($_POST['email']);
    $phoneNumber = htmlspecialchars($_POST['phone_number']);
    $birthDate = htmlspecialchars($_POST['birth_date']);
    $gender = isset($_POST['gender']) ? $_POST['gender'] : '';
    $address1 = htmlspecialchars($_POST['address1']);
    $address2 = htmlspecialchars($_POST['address2']);
    $country = htmlspecialchars($_POST['country']);
    $city = htmlspecialchars($_POST['city']);
    $postalCode = htmlspecialchars($_POST['postal_code']);

    // You can now process the data, for example, store it in a database
    // Here I will simply echo the values for demonstration.
    echo "Registration successful! Below are the details you submitted: <br>";
    echo "Full Name: $fullName<br>";
    echo "Email: $email<br>";
    echo "Phone Number: $phoneNumber<br>";
    echo "Birth Date: $birthDate<br>";
    echo "Gender: $gender<br>";
    echo "Address 1: $address1<br>";
    echo "Address 2: $address2<br>";
    echo "Country: $country<br>";
    echo "City: $city<br>";
    echo "Postal Code: $postalCode<br>";
}
?>