# Write your MySQL query statement below
select FirstName, LastName, (select max(City)
                             from Address
                             where Person.PersonId = Address.PersonId) as City
                          , (select max(State)
                             from Address
                             where Person.PersonId = Address.PersonId) as State
from Person;
