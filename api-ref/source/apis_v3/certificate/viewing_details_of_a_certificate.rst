:original_name: ShowCertificate.html

.. _ShowCertificate:

Viewing Details of a Certificate
================================

Function
--------

This API is used to view details of an SSL certificate.

URI
---

GET /v3/{project_id}/elb/certificates/{certificate_id}

.. table:: **Table 1** Path Parameters

   ============== ========= ====== ===========================
   Parameter      Mandatory Type   Description
   ============== ========= ====== ===========================
   project_id     Yes       String Specifies the project ID.
   certificate_id Yes       String Specifies a certificate ID.
   ============== ========= ====== ===========================

Request Parameters
------------------

.. table:: **Table 2** Request header parameters

   +--------------+-----------+--------+--------------------------------------------------+
   | Parameter    | Mandatory | Type   | Description                                      |
   +==============+===========+========+==================================================+
   | X-Auth-Token | Yes       | String | Specifies the token used for IAM authentication. |
   +--------------+-----------+--------+--------------------------------------------------+

Response Parameters
-------------------

**Status code: 200**

.. table:: **Table 3** Response body parameters

   +-------------+---------------------------------------------------------------------------+-----------------------------------------------------------------+
   | Parameter   | Type                                                                      | Description                                                     |
   +=============+===========================================================================+=================================================================+
   | request_id  | String                                                                    | Specifies the request ID. The value is automatically generated. |
   +-------------+---------------------------------------------------------------------------+-----------------------------------------------------------------+
   | certificate | :ref:`CertificateInfo <showcertificate__response_certificateinfo>` object | Specifies the certificate.                                      |
   +-------------+---------------------------------------------------------------------------+-----------------------------------------------------------------+

.. _showcertificate__response_certificateinfo:

.. table:: **Table 4** CertificateInfo

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

   GET https://{ELB_Endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/certificates/5494a835d88f40ff940554992f2f04d4

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "certificate" : {
       "id" : "5494a835d88f40ff940554992f2f04d4",
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "name" : "https_certificatekkkk",
       "type" : "server",
       "domain" : null,
       "description" : "description for certificatehhhh",
       "private_key" : "-----BEGIN PRIVATE KEY-----MIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQDQVAbOLe5xNf4M253Wn9vhdUzojetjv4J+B7kYwsMhRcgdcJ8KCnX1nfzTvI2ksXlTQ2o9BkpStnPetB4s32ZiJRMlk+61iUUMNsHwK2WBX57JT3JgmyVbH8GbmRY0+H3sH1i72luna7rMMD30gLh6QoP3cq7PGWcuZKV7hjd1tjCTQukwMvqV8Icq39buNpIgDOWzEP5AzqXtCOFYn6RTH5SRug4hKNN7sT1eYMslHu7wtEBDKVgrLjOCe/W2f8rLT1zEsoAW2ChlZAPYUBkl/0XuTWRg3CohPPcI+UtlRSfvLDeeQ460swjbwgS/RbJh3sIwlCRLU08kEo04Z9H/AgMBAAECggEAEIeaQqHCWZk/HyYN0Am/GJSGFa2tD60SXY2fUieh8/HlfvCArftGgMaYWPSNCJRMXB7tPwpQu19esjz4Z/cR2Je4fTLPrffGUsHFgZjv5OQBZVe4a5Hj1OcgJYhwCqPs2d9i2wToYNBbcfgh8lSETq8YaXngBO6vES9LMhHkNKKrciu9YkInNEHu6uRJ5g/eGGX3KQynTvVIhnOVGAJvjTXcoU6fm7gYdHAD6jk9lc9MEGpfYI6AdHIwFZcT/RNAxhP82lg2gUJSgAu66FfDjMwQXKbafKdP3zq4Up8a7AlekrguPtfV1vWklg+bUFhgGaiAEYTpAUN9t2DVIiijgQKBgQDnYMMsaF0r557CM1CTXUqgCZo8MKeV2jf2drlxRRwRl33SksQbzAQ/qrLdT7GP3sCGqvkxWY2FPdFYf8kxGcCeZPcIeZYCQAM41pjtsaM8tVbLWVR8UtGBuQoPSph7JNF3Tm/JH/fbwjpjP7dtJ7n8EzkRUNE6aIMHOFEeych/PQKBgQDmf1bMogx63rTcwQ0PEZ9Vt7mTgKYK4aLriWgTWHXPZxUQaYhpjXo6+lMI6DpExiDgBAkMzJGIvS7yQiYWU+wthAr9urbWYdGZlS6VjoTkF6r7VZoILXX0fbuXh6lm8K8IQRfBpJff56p9phMwaBpDNDrfpHB5utBUxs40yIdp6wKBgQC69Cp/xUwTX7GdxQzEJctYiKnBHKcspAg38zJf3bGSXU/jR4eB1lVQhELGI9CbKSdzKM71GyEImix/T7FnJSHIWlho1qVo6AQyduNWnAQD15pr8KAdXGXAZZ1FQcb3KYa+2fflERmazdOTwjYZ0tGqZnXkEeMdSLkmqlCRigWhGQKBgDak/735uP20KKqhNehZpC2dJei7OiIgRhCS/dKASUXHSW4fptBnUxACYocdDxtY4VhafI7FPMdvGl8ioYbvlHFh+X0Xs9r1S8yeWnHoXMb6eXWmYKMJrAoveLa+2cFm1Agf7nLhA4R4lqm9IpV6SKegDUkR4fxp9pPyodZPqBLLAoGBAJkD4wHW54Pwd4Ctfk9ojHjWB7pQlUYpTZO9dm+4fpCMn9Okf43AE2yAOaAP94GdzdDJkxfciXKcsYr9IIukfaoXgjKR7p1zERiWZuFF63SB4aiyX1H7IX0MwHDZQO38a5gZaOm/BUlGKMWXzuEd3fy+1rCUwzOp9LSjtJYf4ege-----END PRIVATE KEY-----",
       "certificate" : "-----BEGIN CERTIFICATE-----MIIC4TCCAcmgAwIBAgICEREwDQYJKoZIhvcNAQELBQAwFzEVMBMGA1UEAxMMTXlDb21wYW55IENBMB4XDTE4MDcwMjEzMjU0N1oXDTQ1MTExNzEzMjU0N1owFDESMBAGA1UEAwwJbG9jYWxob3N0MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA0FQGzi3ucTX+DNud1p/b4XVM6I3rY7+Cfge5GMLDIUXIHXCfCgp19Z3807yNpLF5U0NqPQZKUrZz3rQeLN9mYiUTJZPutYlFDDbB8CtlgV+eyU9yYJslWx/Bm5kWNPh97B9Yu9pbp2u6zDA99IC4ekKD93KuzxlnLmSle4Y3dbYwk0LpMDL6lfCHKt/W7jaSIAzlsxD+QM6l7QjhWJ+kUx+UkboOISjTe7E9XmDLJR7u8LRAQylYKy4zgnv1tn/Ky09cxLKAFtgoZWQD2FAZJf9F7k1kYNwqITz3CPlLZUUn7yw3nkOOtLMI28IEv0WyYd7CMJQkS1NPJBKNOGfR/wIDAQABozowODAhBgNVHREEGjAYggpkb21haW4uY29thwQKuUvJhwR/AAABMBMGA1UdJQQMMAoGCCsGAQUFBwMBMA0GCSqGSIb3DQEBCwUAA4IBAQA8lMQJxaTey7EjXtRLSVlEAMftAQPG6jijNQuvIBQYUDauDT4W2XUZ5wAnjiOyQ83va672K1G9s8n6xlH+xwwdSNnozaKzC87vwSeZKIOdl9I5I98TGKI6OoDaezmzCwQYtHBMVQ4c7Ml8554Ft1mWSt4dMAK2rzNYjvPRLYlzp1HMnI6hkjPk4PCZwKnha0dlScati9CCt3UzXSNJOSLalKdHErH08Iqd+1BchScxCfk0xNITn1HZZGmI+vbmunok3A2lucI14rnsrcbkGYqxGikySN6B2cRLBDK4Y3wChiW6NVYtVqcx5/mZiYsGDVN+9QBd0eYUHce+77s96i3I-----END CERTIFICATE-----",
       "admin_state_up" : true,
       "created_at" : "2019-03-31T22:23:51Z",
       "updated_at" : "2019-03-31T23:26:49Z",
       "expire_time" : "2045-11-17T13:25:47Z"
     },
     "request_id" : "a94af450-5ac0-4185-946c-27a59a16c1d3"
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
