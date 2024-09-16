:original_name: ListCertificates.html

.. _ListCertificates:

Querying Certificates
=====================

Function
--------

This API is used to query all SSL certificates.

Constraints
-----------

This API has the following constraints:

-  Parameters **marker**, **limit**, and **page_reverse** are used for pagination query.
-  Parameters **marker** and **page_reverse** take effect only when they are used together with parameter **limit**.

URI
---

GET /v3/{project_id}/elb/certificates

.. table:: **Table 1** Path Parameters

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =========================

.. table:: **Table 2** Query Parameters

   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                                                         |
   +=================+=================+=================+=====================================================================================================================================================+
   | marker          | No              | String          | Specifies the ID of the last record on the previous page.                                                                                           |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Note:                                                                                                                                               |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | -  This parameter must be used together with **limit**.                                                                                             |
   |                 |                 |                 | -  If this parameter is not specified, the first page will be queried.                                                                              |
   |                 |                 |                 | -  This parameter cannot be left blank or set to an invalid ID.                                                                                     |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | limit           | No              | Integer         | Specifies the number of records on each page.                                                                                                       |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Minimum: **0**                                                                                                                                      |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Maximum: **2000**                                                                                                                                   |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Default: **2000**                                                                                                                                   |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | page_reverse    | No              | Boolean         | Specifies whether to use reverse query. Values:                                                                                                     |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | -  **true**: Query the previous page.                                                                                                               |
   |                 |                 |                 | -  **false** (default): Query the next page.                                                                                                        |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Note:                                                                                                                                               |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | -  This parameter must be used together with **limit**.                                                                                             |
   |                 |                 |                 | -  If **page_reverse** is set to **true** and you want to query the previous page, set the value of **marker** to the value of **previous_marker**. |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | id              | No              | Array           | Specifies a certificate ID.                                                                                                                         |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Multiple IDs can be queried in the format of *id=xxx&id=xxx*.                                                                                       |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | name            | No              | Array           | Specifies the certificate name.                                                                                                                     |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Multiple names can be queried in the format of *name=xxx&name=xxx*.                                                                                 |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | description     | No              | Array           | Provides supplementary information about the certificate.                                                                                           |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Multiple descriptions can be queried in the format of *description=xxx&description=xxx*.                                                            |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up  | No              | Boolean         | Specifies the administrative status of the certificate.                                                                                             |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | This parameter is unsupported. Please do not use it.                                                                                                |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | domain          | No              | Array           | Specifies the domain names used by the server certificate.                                                                                          |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Multiple domain names can be queried in the format of *domain=xxx&domain=xxx*.                                                                      |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+
   | type            | No              | Array           | Specifies the certificate type.                                                                                                                     |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | The value can be **server** or **client**. **server** indicates server certificates, and **client** indicates CA certificates.                      |
   |                 |                 |                 |                                                                                                                                                     |
   |                 |                 |                 | Multiple types can be queried in the format of *type=xxx&type=xxx*.                                                                                 |
   +-----------------+-----------------+-----------------+-----------------------------------------------------------------------------------------------------------------------------------------------------+

Request Parameters
------------------

.. table:: **Table 3** Request header parameters

   +--------------+-----------+--------+--------------------------------------------------+
   | Parameter    | Mandatory | Type   | Description                                      |
   +==============+===========+========+==================================================+
   | X-Auth-Token | Yes       | String | Specifies the token used for IAM authentication. |
   +--------------+-----------+--------+--------------------------------------------------+

Response Parameters
-------------------

**Status code: 200**

.. table:: **Table 4** Response body parameters

   +--------------+--------------------------------------------------------------------------------------+-----------------------------------------------------------------+
   | Parameter    | Type                                                                                 | Description                                                     |
   +==============+======================================================================================+=================================================================+
   | request_id   | String                                                                               | Specifies the request ID. The value is automatically generated. |
   +--------------+--------------------------------------------------------------------------------------+-----------------------------------------------------------------+
   | page_info    | :ref:`PageInfo <listcertificates__response_pageinfo>` object                         | Shows pagination information about certificates.                |
   +--------------+--------------------------------------------------------------------------------------+-----------------------------------------------------------------+
   | certificates | Array of :ref:`CertificateInfo <listcertificates__response_certificateinfo>` objects | Lists the certificates.                                         |
   +--------------+--------------------------------------------------------------------------------------+-----------------------------------------------------------------+

.. _listcertificates__response_pageinfo:

.. table:: **Table 5** PageInfo

   +-----------------+---------+----------------------------------------------------------------------+
   | Parameter       | Type    | Description                                                          |
   +=================+=========+======================================================================+
   | previous_marker | String  | Specifies the ID of the first record in the pagination query result. |
   +-----------------+---------+----------------------------------------------------------------------+
   | next_marker     | String  | Specifies the ID of the last record in the pagination query result.  |
   +-----------------+---------+----------------------------------------------------------------------+
   | current_count   | Integer | Specifies the number of records.                                     |
   +-----------------+---------+----------------------------------------------------------------------+

.. _listcertificates__response_certificateinfo:

.. table:: **Table 6** CertificateInfo

   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                                                                                                      |
   +=======================+=======================+==================================================================================================================================================================================================================================================+
   | admin_state_up        | Boolean               | Specifies the administrative status of the certificate.                                                                                                                                                                                          |
   |                       |                       |                                                                                                                                                                                                                                                  |
   |                       |                       | This parameter is unsupported. Please do not use it.                                                                                                                                                                                             |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | certificate           | String                | Specifies the certificate content. The value must be PEM encoded.                                                                                                                                                                                |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | description           | String                | Provides supplementary information about the certificate.                                                                                                                                                                                        |
   |                       |                       |                                                                                                                                                                                                                                                  |
   |                       |                       | Minimum: **1**                                                                                                                                                                                                                                   |
   |                       |                       |                                                                                                                                                                                                                                                  |
   |                       |                       | Maximum: **255**                                                                                                                                                                                                                                 |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | domain                | String                | Specifies the domain names used by the server certificate.                                                                                                                                                                                       |
   |                       |                       |                                                                                                                                                                                                                                                  |
   |                       |                       | Note the following when using domain names:                                                                                                                                                                                                      |
   |                       |                       |                                                                                                                                                                                                                                                  |
   |                       |                       | -  The value can contain 0 to 10,000 characters and consists of multiple common domain names or wildcard domain names separated by commas. A maximum of 100 domain names are allowed.                                                            |
   |                       |                       | -  A common domain name consists of several labels separated by periods (.). Each label can contain a maximum of 63 characters, including letters, digits, and hyphens (-), and must start and end with a letter or digit. Example: www.test.com |
   |                       |                       | -  A wildcard domain name is a domain name starts with an asterisk (*). Example: \*.test.com                                                                                                                                                     |
   |                       |                       | -  This parameter will take effect only when \**type*\* is set to \**server**.                                                                                                                                                                   |
   |                       |                       | -  SNI certificates of a dedicated load balancer's listener can have up to 200 domain names.                                                                                                                                                     |
   |                       |                       | -  SNI certificates of a shared load balancer's listener can have up to 30 domain names.                                                                                                                                                         |
   |                       |                       |                                                                                                                                                                                                                                                  |
   |                       |                       | Minimum: **1**                                                                                                                                                                                                                                   |
   |                       |                       |                                                                                                                                                                                                                                                  |
   |                       |                       | Maximum: **10000**                                                                                                                                                                                                                               |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id                    | String                | Specifies the certificate ID.                                                                                                                                                                                                                    |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                | Specifies the certificate name.                                                                                                                                                                                                                  |
   |                       |                       |                                                                                                                                                                                                                                                  |
   |                       |                       | Minimum: **1**                                                                                                                                                                                                                                   |
   |                       |                       |                                                                                                                                                                                                                                                  |
   |                       |                       | Maximum: **255**                                                                                                                                                                                                                                 |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | private_key           | String                | Specifies the private key of the certificate used by HTTPS listeners. The value can contain up to 8,192 PEM encoded characters.                                                                                                                  |
   |                       |                       |                                                                                                                                                                                                                                                  |
   |                       |                       | -  This parameter is valid and mandatory only when **type** is set to **server**.                                                                                                                                                                |
   |                       |                       | -  This parameter will be ignored even if **type** is set to **client**. A CA certificate can still be created and used normally.                                                                                                                |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type                  | String                | Specifies the certificate type. The value can be **server** or **client**. **server** indicates server certificates, and **client** indicates CA certificates. The default value is **server**.                                                  |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | created_at            | String                | Specifies the time when the certificate was created.                                                                                                                                                                                             |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | updated_at            | String                | Specifies the time when the certificate was updated.                                                                                                                                                                                             |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | expire_time           | String                | Specifies the time when the certificate expires.                                                                                                                                                                                                 |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | project_id            | String                | Specifies the project ID of the certificate.                                                                                                                                                                                                     |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Example Requests
----------------

.. code-block:: text

   GET https://{ELB_Endpoint}/v3/{project_id}/elb/certificates

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "certificates" : [ {
       "id" : "5494a835d88f40ff940554992f2f04d4",
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "name" : "https_certificatekkkk",
       "type" : "server",
       "domain" : null,
       "description" : "description for certificatehhhh",
       "private_key" : "-----BEGIN PRIVATE KEY-----MIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQDQVAbOLe5xNf4M253Wn9vhdUzojetjv4J+B7kYwsMhRcgdcJ8KCnX1nfzTvI2ksXlTQ2o9BkpStnPetB4s32ZiJRMlk+61iUUMNsHwK2WBX57JT3JgmyVbH8GbmRY0+H3sH1i72luna7rMMD30gLh6QoP3cq7PGWcuZKV7hjd1tjCTQukwMvqV8Icq39buNpIgDOWzEP5AzqXtCOFYn6RTH5SRug4hKNN7sT1eYMslHu7wtEBDKVgrLjOCe/W2f8rLT1zEsoAW2ChlZAPYUBkl/0XuTWRg3CohPPcI+UtlRSfvLDeeQ460swjbwgS/RbJh3sIwlCRLU08kEo04Z9H/AgMBAAECggEAEIeaQqHCWZk/HyYN0Am/GJSGFa2tD60SXY2fUieh8/HlfvCArftGgMaYWPSNCJRMXB7tPwpQu19esjz4Z/cR2Je4fTLPrffGUsHFgZjv5OQBZVe4a5Hj1OcgJYhwCqPs2d9i2wToYNBbcfgh8lSETq8YaXngBO6vES9LMhHkNKKrciu9YkInNEHu6uRJ5g/eGGX3KQynTvVIhnOVGAJvjTXcoU6fm7gYdHAD6jk9lc9MEGpfYI6AdHIwFZcT/RNAxhP82lg2gUJSgAu66FfDjMwQXKbafKdP3zq4Up8a7AlekrguPtfV1vWklg+bUFhgGaiAEYTpAUN9t2DVIiijgQKBgQDnYMMsaF0r557CM1CTXUqgCZo8MKeV2jf2drlxRRwRl33SksQbzAQ/qrLdT7GP3sCGqvkxWY2FPdFYf8kxGcCeZPcIeZYCQAM41pjtsaM8tVbLWVR8UtGBuQoPSph7JNF3Tm/JH/fbwjpjP7dtJ7n8EzkRUNE6aIMHOFEeych/PQKBgQDmf1bMogx63rTcwQ0PEZ9Vt7mTgKYK4aLriWgTWHXPZxUQaYhpjXo6+lMI6DpExiDgBAkMzJGIvS7yQiYWU+wthAr9urbWYdGZlS6VjoTkF6r7VZoILXX0fbuXh6lm8K8IQRfBpJff56p9phMwaBpDNDrfpHB5utBUxs40yIdp6wKBgQC69Cp/xUwTX7GdxQzEJctYiKnBHKcspAg38zJf3bGSXU/jR4eB1lVQhELGI9CbKSdzKM71GyEImix/T7FnJSHIWlho1qVo6AQyduNWnAQD15pr8KAdXGXAZZ1FQcb3KYa+2fflERmazdOTwjYZ0tGqZnXkEeMdSLkmqlCRigWhGQKBgDak/735uP20KKqhNehZpC2dJei7OiIgRhCS/dKASUXHSW4fptBnUxACYocdDxtY4VhafI7FPMdvGl8ioYbvlHFh+X0Xs9r1S8yeWnHoXMb6eXWmYKMJrAoveLa+2cFm1Agf7nLhA4R4lqm9IpV6SKegDUkR4fxp9pPyodZPqBLLAoGBAJkD4wHW54Pwd4Ctfk9ojHjWB7pQlUYpTZO9dm+4fpCMn9Okf43AE2yAOaAP94GdzdDJkxfciXKcsYr9IIukfaoXgjKR7p1zERiWZuFF63SB4aiyX1H7IX0MwHDZQO38a5gZaOm/BUlGKMWXzuEd3fy+1rCUwzOp9LSjtJYf4ege-----END PRIVATE KEY-----",
       "certificate" : "-----BEGIN CERTIFICATE-----MIIC4TCCAcmgAwIBAgICEREwDQYJKoZIhvcNAQELBQAwFzEVMBMGA1UEAxMMTXlDb21wYW55IENBMB4XDTE4MDcwMjEzMjU0N1oXDTQ1MTExNzEzMjU0N1owFDESMBAGA1UEAwwJbG9jYWxob3N0MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA0FQGzi3ucTX+DNud1p/b4XVM6I3rY7+Cfge5GMLDIUXIHXCfCgp19Z3807yNpLF5U0NqPQZKUrZz3rQeLN9mYiUTJZPutYlFDDbB8CtlgV+eyU9yYJslWx/Bm5kWNPh97B9Yu9pbp2u6zDA99IC4ekKD93KuzxlnLmSle4Y3dbYwk0LpMDL6lfCHKt/W7jaSIAzlsxD+QM6l7QjhWJ+kUx+UkboOISjTe7E9XmDLJR7u8LRAQylYKy4zgnv1tn/Ky09cxLKAFtgoZWQD2FAZJf9F7k1kYNwqITz3CPlLZUUn7yw3nkOOtLMI28IEv0WyYd7CMJQkS1NPJBKNOGfR/wIDAQABozowODAhBgNVHREEGjAYggpkb21haW4uY29thwQKuUvJhwR/AAABMBMGA1UdJQQMMAoGCCsGAQUFBwMBMA0GCSqGSIb3DQEBCwUAA4IBAQA8lMQJxaTey7EjXtRLSVlEAMftAQPG6jijNQuvIBQYUDauDT4W2XUZ5wAnjiOyQ83va672K1G9s8n6xlH+xwwdSNnozaKzC87vwSeZKIOdl9I5I98TGKI6OoDaezmzCwQYtHBMVQ4c7Ml8554Ft1mWSt4dMAK2rzNYjvPRLYlzp1HMnI6hkjPk4PCZwKnha0dlScati9CCt3UzXSNJOSLalKdHErH08Iqd+1BchScxCfk0xNITn1HZZGmI+vbmunok3A2lucI14rnsrcbkGYqxGikySN6B2cRLBDK4Y3wChiW6NVYtVqcx5/mZiYsGDVN+9QBd0eYUHce+77s96i3I-----END CERTIFICATE-----",
       "admin_state_up" : true,
       "created_at" : "2019-04-21T18:59:43Z",
       "updated_at" : "2019-04-21T18:59:43Z",
       "expire_time" : "2045-11-17T13:25:47Z"
     }, {
       "id" : "7875ccb4c6b44cdb90ab2ab89892ab71",
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "name" : "https_certificatekkkk",
       "type" : "client",
       "domain" : "sda.com",
       "description" : "description for certificatehhhh",
       "private_key" : "-----BEGIN PRIVATE KEY-----MIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQDQVAbOLe5xNf4M253Wn9vhdUzojetjv4J+B7kYwsMhRcgdcJ8KCnX1nfzTvI2ksXlTQ2o9BkpStnPetB4s32ZiJRMlk+61iUUMNsHwK2WBX57JT3JgmyVbH8GbmRY0+H3sH1i72luna7rMMD30gLh6QoP3cq7PGWcuZKV7hjd1tjCTQukwMvqV8Icq39buNpIgDOWzEP5AzqXtCOFYn6RTH5SRug4hKNN7sT1eYMslHu7wtEBDKVgrLjOCe/W2f8rLT1zEsoAW2ChlZAPYUBkl/0XuTWRg3CohPPcI+UtlRSfvLDeeQ460swjbwgS/RbJh3sIwlCRLU08kEo04Z9H/AgMBAAECggEAEIeaQqHCWZk/HyYN0Am/GJSGFa2tD60SXY2fUieh8/HlfvCArftGgMaYWPSNCJRMXB7tPwpQu19esjz4Z/cR2Je4fTLPrffGUsHFgZjv5OQBZVe4a5Hj1OcgJYhwCqPs2d9i2wToYNBbcfgh8lSETq8YaXngBO6vES9LMhHkNKKrciu9YkInNEHu6uRJ5g/eGGX3KQynTvVIhnOVGAJvjTXcoU6fm7gYdHAD6jk9lc9MEGpfYI6AdHIwFZcT/RNAxhP82lg2gUJSgAu66FfDjMwQXKbafKdP3zq4Up8a7AlekrguPtfV1vWklg+bUFhgGaiAEYTpAUN9t2DVIiijgQKBgQDnYMMsaF0r557CM1CTXUqgCZo8MKeV2jf2drlxRRwRl33SksQbzAQ/qrLdT7GP3sCGqvkxWY2FPdFYf8kxGcCeZPcIeZYCQAM41pjtsaM8tVbLWVR8UtGBuQoPSph7JNF3Tm/JH/fbwjpjP7dtJ7n8EzkRUNE6aIMHOFEeych/PQKBgQDmf1bMogx63rTcwQ0PEZ9Vt7mTgKYK4aLriWgTWHXPZxUQaYhpjXo6+lMI6DpExiDgBAkMzJGIvS7yQiYWU+wthAr9urbWYdGZlS6VjoTkF6r7VZoILXX0fbuXh6lm8K8IQRfBpJff56p9phMwaBpDNDrfpHB5utBUxs40yIdp6wKBgQC69Cp/xUwTX7GdxQzEJctYiKnBHKcspAg38zJf3bGSXU/jR4eB1lVQhELGI9CbKSdzKM71GyEImix/T7FnJSHIWlho1qVo6AQyduNWnAQD15pr8KAdXGXAZZ1FQcb3KYa+2fflERmazdOTwjYZ0tGqZnXkEeMdSLkmqlCRigWhGQKBgDak/735uP20KKqhNehZpC2dJei7OiIgRhCS/dKASUXHSW4fptBnUxACYocdDxtY4VhafI7FPMdvGl8ioYbvlHFh+X0Xs9r1S8yeWnHoXMb6eXWmYKMJrAoveLa+2cFm1Agf7nLhA4R4lqm9IpV6SKegDUkR4fxp9pPyodZPqBLLAoGBAJkD4wHW54Pwd4Ctfk9ojHjWB7pQlUYpTZO9dm+4fpCMn9Okf43AE2yAOaAP94GdzdDJkxfciXKcsYr9IIukfaoXgjKR7p1zERiWZuFF63SB4aiyX1H7IX0MwHDZQO38a5gZaOm/BUlGKMWXzuEd3fy+1rCUwzOp9LSjtJYf4ege-----END PRIVATE KEY-----",
       "certificate" : "-----BEGIN CERTIFICATE-----MIIC4TCCAcmgAwIBAgICEREwDQYJKoZIhvcNAQELBQAwFzEVMBMGA1UEAxMMTXlDb21wYW55IENBMB4XDTE4MDcwMjEzMjU0N1oXDTQ1MTExNzEzMjU0N1owFDESMBAGA1UEAwwJbG9jYWxob3N0MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA0FQGzi3ucTX+DNud1p/b4XVM6I3rY7+Cfge5GMLDIUXIHXCfCgp19Z3807yNpLF5U0NqPQZKUrZz3rQeLN9mYiUTJZPutYlFDDbB8CtlgV+eyU9yYJslWx/Bm5kWNPh97B9Yu9pbp2u6zDA99IC4ekKD93KuzxlnLmSle4Y3dbYwk0LpMDL6lfCHKt/W7jaSIAzlsxD+QM6l7QjhWJ+kUx+UkboOISjTe7E9XmDLJR7u8LRAQylYKy4zgnv1tn/Ky09cxLKAFtgoZWQD2FAZJf9F7k1kYNwqITz3CPlLZUUn7yw3nkOOtLMI28IEv0WyYd7CMJQkS1NPJBKNOGfR/wIDAQABozowODAhBgNVHREEGjAYggpkb21haW4uY29thwQKuUvJhwR/AAABMBMGA1UdJQQMMAoGCCsGAQUFBwMBMA0GCSqGSIb3DQEBCwUAA4IBAQA8lMQJxaTey7EjXtRLSVlEAMftAQPG6jijNQuvIBQYUDauDT4W2XUZ5wAnjiOyQ83va672K1G9s8n6xlH+xwwdSNnozaKzC87vwSeZKIOdl9I5I98TGKI6OoDaezmzCwQYtHBMVQ4c7Ml8554Ft1mWSt4dMAK2rzNYjvPRLYlzp1HMnI6hkjPk4PCZwKnha0dlScati9CCt3UzXSNJOSLalKdHErH08Iqd+1BchScxCfk0xNITn1HZZGmI+vbmunok3A2lucI14rnsrcbkGYqxGikySN6B2cRLBDK4Y3wChiW6NVYtVqcx5/mZiYsGDVN+9QBd0eYUHce+77s96i3I-----END CERTIFICATE-----",
       "admin_state_up" : true,
       "created_at" : "2018-10-29T20:16:17Z",
       "updated_at" : "2019-04-06T21:33:24Z",
       "expire_time" : "2045-11-17T13:25:47Z"
     }, {
       "id" : "7f41c96223d34ebaa3c8e836b6625ec0",
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "name" : "asdf",
       "type" : "server",
       "domain" : "sda.com",
       "description" : "",
       "private_key" : "-----BEGIN PRIVATE KEY-----MIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQDQVAbOLe5xNf4M253Wn9vhdUzojetjv4J+B7kYwsMhRcgdcJ8KCnX1nfzTvI2ksXlTQ2o9BkpStnPetB4s32ZiJRMlk+61iUUMNsHwK2WBX57JT3JgmyVbH8GbmRY0+H3sH1i72luna7rMMD30gLh6QoP3cq7PGWcuZKV7hjd1tjCTQukwMvqV8Icq39buNpIgDOWzEP5AzqXtCOFYn6RTH5SRug4hKNN7sT1eYMslHu7wtEBDKVgrLjOCe/W2f8rLT1zEsoAW2ChlZAPYUBkl/0XuTWRg3CohPPcI+UtlRSfvLDeeQ460swjbwgS/RbJh3sIwlCRLU08kEo04Z9H/AgMBAAECggEAEIeaQqHCWZk/HyYN0Am/GJSGFa2tD60SXY2fUieh8/HlfvCArftGgMaYWPSNCJRMXB7tPwpQu19esjz4Z/cR2Je4fTLPrffGUsHFgZjv5OQBZVe4a5Hj1OcgJYhwCqPs2d9i2wToYNBbcfgh8lSETq8YaXngBO6vES9LMhHkNKKrciu9YkInNEHu6uRJ5g/eGGX3KQynTvVIhnOVGAJvjTXcoU6fm7gYdHAD6jk9lc9MEGpfYI6AdHIwFZcT/RNAxhP82lg2gUJSgAu66FfDjMwQXKbafKdP3zq4Up8a7AlekrguPtfV1vWklg+bUFhgGaiAEYTpAUN9t2DVIiijgQKBgQDnYMMsaF0r557CM1CTXUqgCZo8MKeV2jf2drlxRRwRl33SksQbzAQ/qrLdT7GP3sCGqvkxWY2FPdFYf8kxGcCeZPcIeZYCQAM41pjtsaM8tVbLWVR8UtGBuQoPSph7JNF3Tm/JH/fbwjpjP7dtJ7n8EzkRUNE6aIMHOFEeych/PQKBgQDmf1bMogx63rTcwQ0PEZ9Vt7mTgKYK4aLriWgTWHXPZxUQaYhpjXo6+lMI6DpExiDgBAkMzJGIvS7yQiYWU+wthAr9urbWYdGZlS6VjoTkF6r7VZoILXX0fbuXh6lm8K8IQRfBpJff56p9phMwaBpDNDrfpHB5utBUxs40yIdp6wKBgQC69Cp/xUwTX7GdxQzEJctYiKnBHKcspAg38zJf3bGSXU/jR4eB1lVQhELGI9CbKSdzKM71GyEImix/T7FnJSHIWlho1qVo6AQyduNWnAQD15pr8KAdXGXAZZ1FQcb3KYa+2fflERmazdOTwjYZ0tGqZnXkEeMdSLkmqlCRigWhGQKBgDak/735uP20KKqhNehZpC2dJei7OiIgRhCS/dKASUXHSW4fptBnUxACYocdDxtY4VhafI7FPMdvGl8ioYbvlHFh+X0Xs9r1S8yeWnHoXMb6eXWmYKMJrAoveLa+2cFm1Agf7nLhA4R4lqm9IpV6SKegDUkR4fxp9pPyodZPqBLLAoGBAJkD4wHW54Pwd4Ctfk9ojHjWB7pQlUYpTZO9dm+4fpCMn9Okf43AE2yAOaAP94GdzdDJkxfciXKcsYr9IIukfaoXgjKR7p1zERiWZuFF63SB4aiyX1H7IX0MwHDZQO38a5gZaOm/BUlGKMWXzuEd3fy+1rCUwzOp9LSjtJYf4ege-----END PRIVATE KEY-----",
       "certificate" : "-----BEGIN CERTIFICATE-----MIIC4TCCAcmgAwIBAgICEREwDQYJKoZIhvcNAQELBQAwFzEVMBMGA1UEAxMMTXlDb21wYW55IENBMB4XDTE4MDcwMjEzMjU0N1oXDTQ1MTExNzEzMjU0N1owFDESMBAGA1UEAwwJbG9jYWxob3N0MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA0FQGzi3ucTX+DNud1p/b4XVM6I3rY7+Cfge5GMLDIUXIHXCfCgp19Z3807yNpLF5U0NqPQZKUrZz3rQeLN9mYiUTJZPutYlFDDbB8CtlgV+eyU9yYJslWx/Bm5kWNPh97B9Yu9pbp2u6zDA99IC4ekKD93KuzxlnLmSle4Y3dbYwk0LpMDL6lfCHKt/W7jaSIAzlsxD+QM6l7QjhWJ+kUx+UkboOISjTe7E9XmDLJR7u8LRAQylYKy4zgnv1tn/Ky09cxLKAFtgoZWQD2FAZJf9F7k1kYNwqITz3CPlLZUUn7yw3nkOOtLMI28IEv0WyYd7CMJQkS1NPJBKNOGfR/wIDAQABozowODAhBgNVHREEGjAYggpkb21haW4uY29thwQKuUvJhwR/AAABMBMGA1UdJQQMMAoGCCsGAQUFBwMBMA0GCSqGSIb3DQEBCwUAA4IBAQA8lMQJxaTey7EjXtRLSVlEAMftAQPG6jijNQuvIBQYUDauDT4W2XUZ5wAnjiOyQ83va672K1G9s8n6xlH+xwwdSNnozaKzC87vwSeZKIOdl9I5I98TGKI6OoDaezmzCwQYtHBMVQ4c7Ml8554Ft1mWSt4dMAK2rzNYjvPRLYlzp1HMnI6hkjPk4PCZwKnha0dlScati9CCt3UzXSNJOSLalKdHErH08Iqd+1BchScxCfk0xNITn1HZZGmI+vbmunok3A2lucI14rnsrcbkGYqxGikySN6B2cRLBDK4Y3wChiW6NVYtVqcx5/mZiYsGDVN+9QBd0eYUHce+77s96i3I-----END CERTIFICATE-----",
       "admin_state_up" : true,
       "created_at" : "2019-03-31T22:23:51Z",
       "updated_at" : "2019-03-31T23:26:49Z",
       "expire_time" : "2045-11-17T13:25:47Z"
     } ],
     "page_info" : {
       "previous_marker" : "5494a835d88f40ff940554992f2f04d4",
       "current_count" : 3
     },
     "request_id" : "a27e7ae6-d901-4ec2-8e66-b8a1413819ad"
   }

Status Codes
------------

=========== ===================
Status Code Description
=========== ===================
200         Successful request.
=========== ===================

Error Codes
-----------

See :ref:`Error Codes <errorcode>`.
