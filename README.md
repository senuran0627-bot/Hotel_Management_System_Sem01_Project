# Hotel Management System

This is a beginner-friendly C++ console project for the hotel management system
requirements. The implementation is in [main.cpp](main.cpp).

## Default login

```text
Username: hotelstaff@1234
Password: staff1234hotel
```

## Implemented components

- User authentication, registration, updates, deletion, password changes, and logout
- Customer registration, searching, updates, deletion, history, current customers, and feedback
- Room creation, updates, deletion, searching, availability, statuses, and maintenance
- Room bookings, reservation searching/updating/cancellation, confirmations, check-in, and check-out
- Food menu, food orders, food bills, table reservations, and kitchen order status
- Staff records, job roles, attendance, and salary display
- Room, restaurant, service, discount, tax, final bill, payment, and invoice output
- Session management report with income, occupancy, booking, customer, staff, and attendance totals

## Run in Code::Blocks

1. Open Code::Blocks and choose **File > New > Project > Console application**.
2. Select **C++** and create the project in this folder.
3. Add `main.cpp` to the project, or replace the generated source with this file.
4. Choose **Build > Build and run**.

The program keeps records in memory, so data is reset when the program closes.
Invoices are saved as `invoice_<booking-id>.txt` in the program's working folder.
File/database persistence and historical daily/monthly reports are natural next
improvements after the core project is understood.