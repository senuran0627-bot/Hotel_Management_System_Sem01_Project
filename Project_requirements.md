COMPONENT 1
User authentication & system administration
This component controls access to the system. Only authorized users can log in according
to their roles.
Tasks
Task 1 - Log into the system
Task 2 - Username and password validation
Task 3 - Register new users
Task 4 – Update the user information
Task 5 - Delete user accounts
Task 6 - Change the password
Task 7 - Logout from the system
COMPONENT 2
Online booking & reservation management
This component allows customers to reserve rooms online and helps staff manage
reservations.
Tasks
Task 1 – Book rooms online
Task 2 - Search reservation
Task 3 – Update the reservation
Task 4 - Cancel the reservation
Task 5 - Check the room availability
Task 6 - Generate booking confirmation
Task 7 - Check-in customer
Task 8 - Check-out customer

---

COMPONENT 3
Customer management
This component manages all customer records.
Tasks
Task 1 - Register a new customer
Task 2 - Search the customer
Task 3 - Update the customer details
Task 4 - Delete customer record
Task 5 – Display the customer history
Task 6 - View current customers
Task 7 - Customer feedbacks
COMPONENT 4
Room management
This component manages hotel rooms and room availability.
Tasks
Task 1 – Add new room
Task 2 – Update the room information
Task 3 - Delete room
Task 4 - Search room
Task 5 - View available rooms
Task 6 - Update the room status
(Available, Occupied, Reserved, Cleaning)
Task 7 - Room maintenance management
COMPONENT 5

---

Restaurant & food management
This component manages restaurant services and customer food orders.
Tasks
Task 1 - Display food menu
Task 2 - Add food items
Task 3 - Update the menu
Task 4 - Remove menu items
Task 5 - Place restaurant order
Task 6 - Calculate food bill
Task 7 - Manage table reservations
Task 8 - Kitchen order management
COMPONENT 6
Staff management
This component manages hotel employees.
Tasks
Task 1 - Add new staff
Task 2 - Search staff
Task 3 - Update staff details
Task 4 - Remove staff
Task 5 - Assign job roles
Task 6 - Record attendance
Task 7 - Calculate monthly salary
Task 8 - Display the staff information
COMPONENT 7

---

Billing & payment management
This component calculates all hotel charges and generates customer bills.
Tasks
Task 1 – Calculate the room charges
Task 2 - Calculate the restaurant charges
Task 3 - Calculate the service charges
Task 4 - Apply discounts
Task 5 - Calculate tax
Task 6 - Generate final bill
Task 7 - Process payment
Task 8 - Print/Save invoice
COMPONENT 8
Reports & business analysis
This component generates reports to help hotel management make business decisions.
Tasks
Task 1 - Daily income report
Task 2 - Monthly income report
Task 3 - Room occupancy report
Task 4 - Restaurant sales report
Task 5 - Customer booking report
Task 6 - Staff attendance report
Task 7 - Income analysis
Task 8 - Compare daily and monthly performance
Task 9 - Generate complete management report

---

COMPONENT 01
Task 1 – Log into the system
In here the hotel staff can log into the system using there username and password
Algorithm
1. Start
2. Display the login screen
3. Ask user to enter the username
4. Ask user to enter the password
5. Store the username and password
6. End

---

Task 2 – Username and password validation
In here the system will check whether the username and password correct or not. After the
system will continue.
Algorithm
1. Start
2. Check whether the entered username and stored username are same or not
3. Check whether the entered password and stored password are same or not
4. If the username and password are correct
• Display “login successful”
• Continuing to the menu
5. Else
• Display “Invalid username or password”
• Ask user to enter the details again
6. End

---

Task 3 – Register new users
In here the system allows to register new users.
Algorithm
1. Start
2. Enter user details.
3. Check whether the username already exists.
4. If it exists,
o Display "Username Already Exists".
5. Otherwise,
o Save the new user information.
o Display "User Registered Successfully".
6. End

---

Task 4 – Update the user information
In here system allows to update the user details.
Algorithm
1. Start
2. Enter the user ID.
3. Search for the user.
4. If the user is found,
o Display the current information.
o Enter new information.
o Save the updated details.
o Display "User Updated Successfully".
5. Otherwise,
o Display "User Not Found".
6. End

---

Task 5 – Delete user account
In here the system allows to user to delete their accounts.
Algorithm
1. Start
2. Enter the user ID.
3. Search for the user.
4. If the user exists,
o Ask for confirmation.
o Delete the user account.
o Display "User Deleted Successfully".
5. Otherwise,
o Display "User Not Found".
6. End

---

Task 6 – Change the password
In here the user can change their password.
Algorithm
1. Start
2. Enter current password.
3. Verify the current password.
4. If correct,
o Enter the new password.
o Confirm the new password.
o Save the new password.
o Display "Password Changed Successfully"
5. Otherwise,
o Display "Incorrect Current Password"
6. End

---

Task 7 – Logout from the system
In here the user can logout from the system.
Algorithm
1. Start
2. Save any pending changes.
3. End the current session.
4. Return to the Login page.
5. End

---

COMPONENT 02
Task 1 – Book rooms online
This task allows customers to book a hotel room by entering their personal details and
selecting an available room.
Algorithm
1. Start.
2. Enter customer details.
3. Enter check-in date and check-out date.
4. Show room types and prices
5. Select room type.
6. Check room availability.
7. If a room is available,
o Assign an available room.
o Save the booking details.
o Generate a booking ID.
o Display "Booking Successful."
8. Otherwise,
o Display "Selected room is not available."
9. End.

---

Task 2 – Search Reservation
This task allows staff to search for an existing reservation using the booking ID or customer
name.
Algorithm
1. Start.
2. Enter booking ID
3. Search the reservation details
4. If the reservation is found,
o Display reservation details.
5. Otherwise,
o Display "Reservation Not Found."
6. End.

---

Task 3 – Update Reservation
This task allows staff to modify an existing reservation.
Algorithm
1. Start.
2. Enter booking ID.
3. Search for the reservation.
4. If the reservation exists,
o Display current reservation details.
o Enter updated booking information.
o Check room availability if necessary.
o Save the updated reservation.
o Display "Reservation Updated Successfully."
5. Otherwise,
o Display "Reservation Not Found."
6. End.

---

Task 4 – Cancel Reservation
This task allows customers or staff to cancel an existing reservation.
Algorithm
1. Start.
2. Enter booking ID.
3. Search for the reservation.
4. If the reservation exists,
o Ask for cancellation confirmation.
o Cancel the reservation.
o Update room status to Available.
o Display "Reservation Cancelled Successfully."
5. Otherwise,
o Display "Reservation Not Found."
6. End.

---

Task 5 – Check Room Availability
This task checks whether rooms are available for the selected dates.
Algorithm
1. Start.
2. Enter check-in date.
3. Enter check-out date.
4. Search available rooms.
5. If rooms are available,
o Display available room list.
6. Otherwise,
o Display "No Rooms Available."
7. End.

---

Task 6 – Generate Booking Confirmation
This task generates a booking confirmation after a successful reservation.
Algorithm
1. Start.
2. Retrieving booking details.
3. Generate booking confirmation.
4. Include booking ID, customer name, room details, check-in date, and check-out
date.
5. Display the booking confirmation.
6. Save or print the confirmation.
7. End.

---

Task 7 – Check-in Customer
This task records the customer's arrival and assigns the booked room.
Algorithm
1. Start.
2. Enter booking ID.
3. Search the reservation.
4. If the reservation is valid,
o Verify customer details.
o Assign the reserved room.
o Update room status to Occupied.
o Update reservation status to Checked-in.
o Display "Check-in Successful."
5. Otherwise,
o Display "Invalid Reservation."
6. End.

---

Task 8 – Check-out Customer
This task records the customer's departure and completes the reservation.
Algorithm
1. Start.
2. Enter booking ID.
3. Search the reservation.
4. If the reservation exists,
o Calculate the final bill.
o Process the payment.
o Update room status to Available.
o Update reservation status to Checked-out.
o Display "Check-out Successful."
5. Otherwise,
o Display "Reservation Not Found."
6. End.

---

COMPONENT 03
Task 1 – Register New Customer
This task allows staff to register a new customer by storing their personal information in the
system.
Algorithm
1. Start.
2. Enter customer details (Name, NIC/Passport, Phone Number, Email, Address).
3. Check whether the customer already exists.
4. If the customer already exists,
o Display "Customer Already Registered."
5. Otherwise,
o Generate a Customer ID.
o Save the customer details.
o Display "Customer Registered Successfully."
6. End.

---

Task 2 – Search Customer
This task allows staff to search for a customer using the Customer ID.
Algorithm
1. Start.
2. Enter Customer ID
3. Search the customer details
4. If the customer is found,
o Display customer details.
5. Otherwise,
o Display "Customer Not Found."
6. End.

---

Task 3 – Update Customer Details
This task allows staff to modify a customer's information.
Algorithm
1. Start.
2. Enter Customer ID.
3. Search for the customer.
4. If the customer is found,
o Display current customer details.
o Enter updated information.
o Save the updated details.
o Display "Customer Details Updated Successfully."
5. Otherwise,
o Display "Customer Not Found."
6. End.

---

Task 4 – Delete Customer Record
This task removes a customer's record from the system when it is no longer needed.
Algorithm
1. Start.
2. Enter Customer ID.
3. Search for the customer.
4. If the customer is found,
o Ask for confirmation.
o Delete the customer record.
o Display "Customer Record Deleted Successfully."
5. Otherwise,
o Display "Customer Not Found."
6. End.

---

Task 5 – Display Customer History
This task displays the customer's previous bookings, payments, and hotel visits.
Algorithm
1. Start.
2. Enter Customer ID.
3. Search for the customer.
4. If the customer is found,
o Retrieve booking history.
o Retrieve payment history.
o Display the complete customer history.
5. Otherwise,
o Display "Customer History Not Available."
6. End.

---

Task 6 – View Current Customers
This task displays all customers who are currently staying in the hotel.
Algorithm
1. Start.
2. Retrieve the list of checked-in customers.
3. If customers are currently staying,
o Display customer names, room numbers, check-in dates, and check-out
dates.
4. Otherwise,
o Display "No Current Customers."
5. End.

---

Task 7 – Customer Feedback Management
This task records customer feedback and allows staff to review it to improve hotel services.
Algorithm
1. Start.
2. Enter Customer ID.
3. Check whether the customer exists.
4. If the customer exists,
o Enter customer feedback and rating.
o Save the feedback.
o Display "Feedback Submitted Successfully."
5. Otherwise,
o Display "Customer Not Found."
6. End.

---

COMPONENT 04
Task 1 – Add New Room
This task allows staff to add a new room to the hotel with its details.
Algorithm
1. Start.
2. Enter room details (Room Number, Room Type, Price, Floor, Capacity).
3. Check whether the room number already exists.
4. If the room already exists,
o Display "Room Already Exists."
5. Otherwise,
o Set room status as Available.
o Save the room details.
o Display "Room Added Successfully."
6. End.

---

Task 2 – Update Room Information
This task allows staff to update the details of an existing room.
Algorithm
1. Start.
2. Enter the room number.
3. Search for the room.
4. If the room is found,
o Display current room details.
o Enter updated information.
o Save the updated details.
o Display "Room Information Updated Successfully."
5. Otherwise,
o Display "Room Not Found."
6. End.

---

Task 3 – Delete Room
This task removes a room from the system when it is no longer available for use.
Algorithm
1. Start.
2. Enter the room number.
3. Search for the room.
4. If the room is found,
o Check whether the room is occupied or reserved.
o If the room is occupied or reserved,
▪ Display "Cannot Delete an Occupied or Reserved Room."
o Otherwise,
▪ Ask for confirmation.
▪ Delete the room record.
▪ Display "Room Deleted Successfully."
5. Otherwise,
o Display "Room Not Found."
6. End.

---

Task 4 – Search Room
This task allows staff to search for a room using its room number
Algorithm
1. Start.
2. Enter the room number
3. Search the room details
4. If the room is found,
o Display room details.
5. Otherwise,
o Display "Room Not Found."
6. End.

---

Task 5 – View Available Rooms
This task displays all rooms that are currently available for booking.
Algorithm
1. Start.
2. Retrieve the list of rooms with the status Available.
3. If available rooms exist,
o Display room number, room type, capacity, and price.
4. Otherwise,
o Display "No Available Rooms."
5. End.

---

Task 6 – Update Room Status
This task updates the current status of a room based on its condition or occupancy.
Algorithm
1. Start.
2. Enter the room number.
3. Search for the room.
4. If the room is found,
o Select the new room status (Available, Occupied, Reserved, or Cleaning).
o Update the room status.
o Save the changes.
o Display "Room Status Updated Successfully."
5. Otherwise,
o Display "Room Not Found."
6. End.

---

Task 7 – Room Maintenance Management
This task records and manages room maintenance requests to ensure rooms remain in
good condition.
Algorithm
1. Start.
2. Enter the room number.
3. Search for the room.
4. If the room is found,
o Enter maintenance details.
o Update the room status to Maintenance or Cleaning.
o Save the maintenance record.
o Display "Maintenance Record Saved Successfully."
5. When maintenance is completed,
o Update the room status to Available.
o Display "Room is Ready for Booking."
6. End.

---

COMPONENT 05
Task 1 – Display Food Menu
This task displays the available food and beverage menu with prices.
Algorithm
1. Start.
2. Retrieve the food menu from the database.
3. If menu items are available,
o Display the list of available food items, categories, and prices.
4. Otherwise,
o Display "Menu is Currently Unavailable."
5. End.

---

Task 2 – Add Food Items
This task allows staff to add new food or beverage items to the menu.
Algorithm
1. Start.
2. Enter food item details (Item Name, Category, Price).
3. Check whether the item already exists.
4. If the item already exists,
o Display "Food Item Already Exists."
5. Otherwise,
o Save the food item.
o Display "Food Item Added Successfully."
6. End.

---

Task 3 – Update Menu
This task allows staff to modify existing food menu items.
Algorithm
1. Start.
2. Enter the food item name
3. Search for the food item.
4. If the item is found,
o Display current details.
o Enter updated information.
o Save the updated menu.
o Display "Menu Updated Successfully."
5. Otherwise,
o Display "Food Item Not Found."
6. End.

---

Task 4 – Remove Menu Items
This task removes unavailable or discontinued food items from the menu.
Algorithm
1. Start.
2. Enter the food item name
3. Search for the food item.
4. If the item is found,
o Ask for confirmation.
o Remove the food item from the menu.
o Display "Food Item Removed Successfully."
5. Otherwise,
o Display "Food Item Not Found."
6. End.

---

Task 5 – Place Restaurant Order
This task allows customers or staff to place food orders.
Algorithm
1. Start.
2. Enter the customer number or table number.
3. Display the food menu.
4. Select one or more food items.
5. Enter the quantity for each item.
6. Calculate the order total.
7. Save the order details.
8. Send the order to the kitchen.
9. Display "Order Placed Successfully."
10. End.

---

Task 6 – Calculate Food Bill
This task calculates the total amount for the customer's food order.
Algorithm
1. Start.
2. Retrieve the customer's order.
3. Calculate the total price of all ordered items.
4. Apply any discounts or service charges, if applicable.
5. Calculate the final food bill.
6. Display the total amount.
7. Save the bill details.
8. End.

---

Task 7 – Manage Table Reservations
This task manages restaurant table bookings for customers.
Algorithm
1. Start.
2. Enter the customer details.
3. Enter the reservation date and time.
4. Check table availability.
5. If a table is available,
o Assign the table.
o Save the reservation.
o Display "Table Reserved Successfully."
6. Otherwise,
o Display "No Tables Available."
7. End.

---

Task 8 – Kitchen Order Management
This task manages food orders sent to the kitchen and tracks their preparation status.
Algorithm
1. Start.
2. Receive the food order from the restaurant.
3. Display the order in the kitchen.
4. Update the order status as Preparing.
5. When the food is ready,
o Update the status as Ready to Serve.
6. Notify the restaurant staff.
7. Display "Order Completed Successfully."
8. End

---

COMPONANT 06
Task 1 – Add New Staff
This task allows the administrator to add a new employee to the hotel staff database.
Algorithm
1. Start.
2. Enter staff details (Staff ID, Name, Position, Department, Phone Number, Address,
Salary).
3. Check whether the Staff ID already exists.
4. If the Staff ID already exists,
o Display "Staff Member Already Exists."
5. Otherwise,
o Save the staff details.
o Display "Staff Added Successfully."
6. End.

---

Task 2 – Search Staff
This task allows staff information to be searched using the Staff ID
Algorithm
1. Start.
2. Enter Staff ID
3. Search the staff database.
4. If the staff member is found,
o Display staff details.
5. Otherwise,
o Display "Staff Member Not Found."
6. End.

---

Task 3 – Update Staff Details
This task allows the administrator to modify staff information.
Algorithm
1. Start.
2. Enter Staff ID.
3. Search for the staff member.
4. If the staff ID is found,
o Display current staff details.
o Enter updated information.
o Save the updated details.
o Display "Staff Details Updated Successfully."
5. Otherwise,
o Display "Staff ID Not Found."
6. End.

---

Task 4 – Remove Staff
This task removes a staff member's record from the system.
Algorithm
1. Start.
2. Enter Staff ID.
3. Search for the staff member.
4. If the staff member is found,
o Ask for confirmation.
o Remove the staff record.
o Display "Staff Removed Successfully."
5. Otherwise,
o Display "Staff Member Not Found."
6. End.

---

Task 5 – Assign Job Roles
This task assigns or updates job roles for hotel employees.
Algorithm
1. Start.
2. Enter Staff ID.
3. Search for the staff member.
4. If the staff member is found,
o Display available job roles.
o Select the appropriate job role.
o Save the assigned role.
o Display "Job Role Assigned Successfully."
5. Otherwise,
o Display "Staff Member Not Found."
6. End.

---

Task 6 – Record Attendance
This task records the daily attendance of hotel staff.
Algorithm
1. Start.
2. Enter Staff ID.
3. Search for the staff member.
4. If the staff member is found,
o Mark attendance (Present, Absent, or Leave).
o Save the attendance record with the current date.
o Display "Attendance Recorded Successfully."
5. Otherwise,
o Display "Staff Member Not Found."
6. End.

---

Task 7 – Calculate Monthly Salary
This task calculates the monthly salary of each employee based on salary details and
attendance.
Algorithm
1. Start.
2. Enter Staff ID.
3. Search for the staff member.
4. If the staff member is found,
o Retrieve the basic salary.
o Retrieve attendance records.
o Calculate the monthly salary.
o Display the total monthly salary.
5. Otherwise,
o Display "Staff Member Not Found."
6. End.

---

Task 8 – Display Staff Information
This task displays complete information about hotel employees.
Algorithm
1. Start.
2. Retrieve the staff records.
3. If staff records are available,
o Display Staff ID, Name, Position, Department, Contact Number, and Salary.
4. Otherwise,
o Display "No Staff Records Available."
5. End.

---

COMPONENT 07
Task 1 – Calculate Room Charges
This task calculates the total room charges based on the room rate and the number of
nights stayed.
Algorithm
1. Start.
2. Enter the booking ID.
3. Retrieve the room rate and number of nights.
4. Calculate the room charges.
o Room Charges = Room Rate × Number of Nights
5. Display the room charges.
6. Save the calculated amount.
7. End.

---

Task 2 – Calculate Restaurant Charges
This task calculates the total cost of all food and beverage orders.
Algorithm
1. Start.
2. Enter the booking ID or customer ID.
3. Retrieve all restaurant orders.
4. Calculate the total restaurant charges.
5. Display the restaurant charges.
6. Save the calculated amount.
7. End.

---

Task 3 – Calculate Service Charges
This task calculates additional service charges such as laundry, spa, transportation, or
room service.
Algorithm
1. Start.
2. Enter the booking ID.
3. Retrieve all additional services used.
4. Calculate the total service charges.
5. Display the service charges.
6. Save the calculated amount.
7. End.

---

Task 4 – Apply Discounts
This task applies Available discounts to the customer's bill.
Algorithm
1. Start.
2. Enter the booking ID.
3. Retrieve the total bill amount.
4. Check whether the any discounts are available.
5. If available,
o Calculate the discount amount.
o Deduct the discount from the total bill.
o Display the updated bill amount.
6. Otherwise,
o Display "No Discount Available."
7. Save the updated bill.
8. End.

---

Task 5 – Calculate Tax
This task calculates the applicable tax on the customer's bill.
Algorithm
1. Start.
2. Enter the booking ID.
3. Retrieve the bill amount after applying discounts.
4. Calculate the tax amount.
5. Add the tax to the bill.
6. Display the tax amount and updated total.
7. Save the updated bill.
8. End.

---

Task 6 – Generate Final Bill
This task prepares the customer's final bill by combining all charges.
Algorithm
1. Start.
2. Enter the booking ID.
3. Retrieve room charges.
4. Retrieve restaurant charges.
5. Retrieve service charges.
6. Apply discounts.
7. Calculate tax.
8. Calculate the final bill amount.
9. Display the complete bill.
10. Save the final bill.
11. End.

---

Task 7 – Process Payment
This task records the customer's payment and completes the billing process.
Algorithm
1. Start.
2. Enter the booking ID.
3. Display the final bill amount.
4. Select the payment method (Cash, Card, or Online Payment).
5. Receive the payment.
6. If the payment is successful,
o Update the payment status as Paid.
o Display "Payment Successful."
7. Otherwise,
o Display "Payment Failed. Please Try Again."
8. End.

---

Task 8 – Print/Save Invoice
This task generates an invoice and allows it to be printed or saved for future reference.
Algorithm
1. Start.
2. Enter the booking ID.
3. Retrieve the final bill and payment details.
4. Generate the invoice.
5. Display the invoice.
6. Ask whether to print or save the invoice.
7. Print or save the invoice according to the user's choice.
8. Display "Invoice Generated Successfully."
9. End.

---

COMPONENT 08
Task 1 – Daily Income Report
This task generates a report showing the hotel's total income for a selected day.
Algorithm
1. Start.
2. Enter the report date.
3. Retrieve all payments made on the selected date.
4. Calculate the total daily income.
5. Generate the daily income report.
6. Display the report.
7. Save or print the report.
8. End.

---

Task 2 – Monthly Income Report
This task generates a report showing the hotel's total income for a selected month.
Algorithm
1. Start.
2. Enter the month and year.
3. Retrieve all payments made during the selected month.
4. Calculate the total monthly income.
5. Generate the monthly income report.
6. Display the report.
7. Save or print the report.
8. End.

---

Task 3 – Room Occupancy Report
This task generates a report showing room occupancy and availability.
Algorithm
1. Start.
2. Retrieve all room records.
3. Count occupied rooms.
4. Count available rooms.
5. Count reserved rooms.
6. Calculate the occupancy rate.
7. Generate the room occupancy report.
8. Display the report.
9. End.

---

Task 4 – Restaurant Sales Report
This task generates a report showing restaurant sales for a selected period.
Algorithm
1. Start.
2. Enter the report period.
3. Retrieve all restaurant orders.
4. Calculate the total restaurant sales.
5. Generate the restaurant sales report.
6. Display the report.
7. Save or print the report.
8. End.

---

Task 5 – Customer Booking Report
This task generates a report of customer bookings during a selected period.
Algorithm
1. Start.
2. Enter the report period.
3. Retrieve all booking records.
4. Count the total number of bookings.
5. Generate the customer booking report.
6. Display the report.
7. Save or print the report.
8. End.

---

Task 6 – Staff Attendance Report
This task generates a report showing staff attendance records.
Algorithm
1. Start.
2. Enter the report period.
3. Retrieve staff attendance records.
4. Calculate the attendance summary for each staff member.
5. Generate the staff attendance report.
6. Display the report.
7. Save or print the report.
8. End.

---

Task 7 – Income Analysis
This task analyzes the hotel's income by identifying total revenue and its main sources.
Algorithm
1. Start.
2. Retrieve room income.
3. Retrieve restaurant income.
4. Retrieve service income.
5. Calculate the total income.
6. Analyze the contribution of each income source.
7. Generate the income analysis report.
8. Display the analysis.
9. End.

---

Task 8 – Compare Daily and Monthly Performance
This task compares the selected day's income with the average daily income of the
selected month to evaluate business performance.
Algorithm
1. Start.
2. Enter the selected date.
3. Retrieve the daily income.
4. Retrieve the total monthly income.
5. Calculate the average daily income for the month.
6. Compare the selected day's income with the monthly average.
7. Display the performance result (Above Average, Average, or Below Average).
8. Generate the comparison report.
9. End.

---

Task 9 – Generate Complete Management Report
This task combines all hotel reports into one comprehensive management report for
decision-making.
Algorithm
1. Start.
2. Retrieve the daily income report.
3. Retrieve the monthly income report.
4. Retrieve the room occupancy report.
5. Retrieve the restaurant sales report.
6. Retrieve the customer booking report.
7. Retrieve the staff attendance report.
8. Retrieve the income analysis report.
9. Combine all reports into a complete management report.
10. Display the management report.
11. Save or print the report.
12. End