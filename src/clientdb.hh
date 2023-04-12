#ifndef OCTETOS_CLIENTDB_HH
#define OCTETOS_CLIENTDB_HH

/**
 *
 *  This file is part of octetos-db-abstract.
 *  octetos-db-abstract is a C++ API to access database, abstract component.
 *  Copyright (C) 2018  Azael Reyes
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * */

#if EXPORTING_OCTETOS_DB_DLL
	#if _MSC_VER
		#define OCTETOS_DB_DECLSPCE_DLL __declspec(dllexport)
	#elif __GNUG__

	#endif
#elif IMPORTING_OCTETOS_DB_DLL
	#if _MSC_VER
		#define OCTETOS_DB_DECLSPCE_DLL __declspec(dllimport)
	#elif __GNUG__

	#endif
#else
	#define OCTETOS_DB_DECLSPCE_DLL
#endif

#if defined(__linux__) && defined IDE_CODEBLOCKS
    #include "config-cb.h"
    #include <octetos/core/Version.hh>
    #include <octetos/core/Error.hh>
    #include <arpa/inet.h>
#elif  defined(__linux__)
    #include "config.h"
    #include <octetos/core/Error.hh>
    #include <arpa/inet.h>
#elif MSYS2
    #include "config-cb.h"
    #include <core/src/Error.hh>
#elif defined(_WIN32) || defined(_WIN64)
    #include "config-cb.h"
    #include <Error.hh>
#else
    #error "Plataforma desconocida"
#endif

#include <vector>
#include <string>

namespace octetos
{
namespace db
{
	typedef void* Handler;
	typedef Handler Connection;
	typedef Handler Result;

#if defined OCTETOS_DB_HIGHWORD
	typedef unsigned long long RowNumber;
	typedef long long Integer;
	typedef unsigned long long FieldNumber;
#elif defined OCTETOS_DB_MEDIUMWORD
	typedef unsigned long RowNumber;
	typedef long Integer;
	typedef unsigned long FieldNumber;
#elif defined OCTETOS_DB_LOWWORD
	typedef unsigned int RowNumber;
	typedef int Integer;
	typedef unsigned int FieldNumber;
#endif

	enum ErrorCodes
	{
		UnknowError = core::Error::ROOFCODE,
		ErrorConection
	};


	class SQLException : public core::Exception
	{
	public:
		virtual ~SQLException() throw();
		SQLException(const std::string& description) throw();
		SQLException(const std::string&, int code) throw() __attribute__ ((deprecated));
		SQLException(const std::string& description,const char* fn,int line) throw();
	private:
		//std::string description;
	};
	class SQLExceptionConnection : public SQLException
	{
	public:
		virtual ~SQLExceptionConnection() throw();
		SQLExceptionConnection(const std::string& description) throw();
		SQLExceptionConnection(const std::string& description, int code) throw() __attribute__ ((deprecated));
		SQLExceptionConnection(const std::string& description,const char* fn,int line) throw();
	};
	class SQLExceptionQuery : public SQLException
	{
	public:
		virtual ~SQLExceptionQuery() throw();
		SQLExceptionQuery(const std::string& description) throw();
		SQLExceptionQuery(const std::string& description, int code) throw() __attribute__ ((deprecated));
		SQLExceptionQuery(const std::string& description,const char* fn,int line) throw();
	};
	class NotSupportedExcetion  : public SQLException
	{
	public:
		virtual ~NotSupportedExcetion() throw();
		NotSupportedExcetion(const std::string& description) throw();
		NotSupportedExcetion(const std::string& description, int code) throw() __attribute__ ((deprecated));
		NotSupportedExcetion(const std::string& description,const char* fn,int line) throw();
	};

	enum TypeServer
	{
		Unknow,
		MySQL,
		PostgreSQL,
		MariaDB
	};
	typedef TypeServer Driver __attribute__ ((deprecated));
	const char* getDriverString(TypeServer);

   	class OCTETOS_DB_DECLSPCE_DLL Datconnect : public core::Object
	{
	public:
		//contructors
   		Datconnect(TypeServer serverType,const std::string& host, unsigned int port,const std::string& database,const std::string& user,const std::string& password);
   		Datconnect(const std::string& host, unsigned int port,const std::string& database,const std::string& user,const std::string& password);
   		Datconnect(const Datconnect&);
		Datconnect();

		//getter
		virtual std::string toString()const;
		const std::string& getHost()const;
		const std::string& getUser()const;
		const std::string& getPassword()const;
		const std::string& getDatabase()const;
		TypeServer getDriver()const;
		unsigned int getPort()const;
		bool getAutocommit()const;

		//setter
		void setHost(const std::string&);
		void setUser(const std::string&);
		void setPassword(const std::string&);
		void setDatabase(const std::string&);
		void setPort(unsigned int);
        void set(TypeServer serverType,const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password);
        void set(const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password);
		void setAutocommit(bool autocommit);

		bool write(const std::string&);
		bool read(const std::string&);

	protected:
		TypeServer driver;
		std::string host;
		std::string user;
		std::string password;
		std::string database;
		unsigned int port;
		bool autocommit;
	};


	class OCTETOS_DB_DECLSPCE_DLL Datresult : public core::Object
	{
	protected:
		Result result;

	public:
		Datresult(void* result);
		Datresult();
		virtual ~Datresult();
		virtual bool nextRow() = 0;
		Result getResult() const;
		const Datresult& operator = (Result);
		//retrive data field by index
		virtual char getchar(FieldNumber field)const = 0;
		virtual unsigned char getuchar(FieldNumber field)const = 0;
		virtual short getshort(FieldNumber field)const = 0;
		virtual unsigned short getushort(FieldNumber field)const = 0;
		virtual int getint(FieldNumber field)const = 0;
		virtual unsigned int getuint(FieldNumber field)const = 0;
		virtual long getl(FieldNumber field)const = 0;
		virtual unsigned long getul(FieldNumber field)const = 0;
		virtual long long getll(FieldNumber field)const = 0;
		virtual unsigned long long getull(FieldNumber field)const = 0;
		virtual float getfloat(FieldNumber field)const = 0;
		virtual double getdouble(FieldNumber field)const = 0;
		virtual std::string getString(FieldNumber field)const = 0;
		//retrive data field by name
		virtual char getchar(const std::string&)const = 0;
		virtual unsigned char getuchar(const std::string&)const = 0;
		virtual short getshort(const std::string&)const = 0;
		virtual unsigned short getushort(const std::string&)const = 0;
		virtual int getint(const std::string&)const = 0;
		virtual unsigned int getuint(const std::string&)const = 0;
		virtual long getl(const std::string&)const = 0;
		virtual unsigned long getul(const std::string&)const = 0;
		virtual long long getll(const std::string&)const = 0;
		virtual unsigned long long getull(const std::string&)const = 0;
		virtual float getfloat(const std::string&)const = 0;
		virtual double getdouble(const std::string&)const = 0;
		virtual std::string getString(const std::string&)const = 0;
	};

	class OCTETOS_DB_DECLSPCE_DLL Connector : public core::Object
	{
	protected:
		Connection conn;
		const Datconnect* datconn;

	protected:
		//void setConnecion(Connection,const Datconnect*);

	public:
		//
		static bool is_ipv4_address(const std::string& str);
		static bool is_ipv6_address(const std::string& str);
		static bool is_valid_domain_name(const std::string& str);
		virtual ~Connector();
		Connector();
		Connection getConnection()const;
		const Datconnect* getDatconection() const;
		const Connector& operator=(const Connector& obj);
		//
		virtual bool connect(const Datconnect& connector)  = 0;
		virtual bool execute(const std::string& str,Datresult&) = 0;
		virtual bool insert(const std::string&,Datresult&) = 0;
		virtual bool select(const std::string& str,Datresult&) = 0;
		virtual bool update(const std::string&,Datresult&) = 0;
		virtual bool remove(const std::string&,Datresult&) = 0;
		virtual bool commit() = 0;
		virtual bool begin() = 0;
		virtual bool rollback() = 0;
		virtual void close() = 0;
		virtual core::Semver getVerionServer() const = 0;
	};

}
}

#endif
