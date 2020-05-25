#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "lib/string.hpp"
#include "lib/vector.hpp"
#include "trip.hpp"
#include "destination.hpp"
#include "user.hpp"

class Database
{
private:
    User* curr_user;
    Vector<Destination> destinations;
    void copy_from(const Database& other);
    void free_memory();
    bool load_destinations();

public:
    Database();
    Database(const Database& other);
    Database& operator=(const Database& other);
    ~Database();

    //! Get user from users.db by name
    User* get_user_by_username(const char* username) const;
    //! Get user from users.db by email
    User* get_user_by_email(const char* email) const;
    //! Get destinaiton by its name
    Destination* get_destination_by_name(const char* name) const;
    //! Get an immutable list of the destinations
    const Vector<Destination>& get_destinations() const;
    //! Save new user to users.db and create personal db file
    bool add_user(User user) const;
    //! Set current user
    bool log_in(const char* username, const char* password);
    //! Get currently logged in user
    User* get_curr_user() const;
    //! Write destinations to destinations.db
    bool save_destinations() const;
    //! Add new destination to local vector; will be saved to file at close
    bool add_destination(Destination dest);

};

#endif // DATABASE_HPP
