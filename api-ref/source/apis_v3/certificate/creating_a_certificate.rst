:original_name: CreateCertificate.html

.. _CreateCertificate:

Creating a Certificate
======================

Function
--------

This API is used to create an SSL certificate for HTTPS listeners.

URI
---

POST /v3/{project_id}/elb/certificates

.. table:: **Table 1** Path Parameters

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =========================

Request Parameters
------------------

.. table:: **Table 2** Request header parameters

   +--------------+-----------+--------+--------------------------------------------------+
   | Parameter    | Mandatory | Type   | Description                                      |
   +==============+===========+========+==================================================+
   | X-Auth-Token | Yes       | String | Specifies the token used for IAM authentication. |
   +--------------+-----------+--------+--------------------------------------------------+

.. table:: **Table 3** Request body parameters

   +-------------+-----------+--------------------------------------------------------------------------------------------+----------------------------+
   | Parameter   | Mandatory | Type                                                                                       | Description                |
   +=============+===========+============================================================================================+============================+
   | certificate | Yes       | :ref:`CreateCertificateOption <createcertificate__request_createcertificateoption>` object | Specifies the certificate. |
   +-------------+-----------+--------------------------------------------------------------------------------------------+----------------------------+

.. _createcertificate__request_createcertificateoption:

.. table:: **Table 4** CreateCertificateOption

   +-----------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Mandatory       | Type            | Description                                                                                                                                                                                                                                      |
   +=======================+=================+=================+==================================================================================================================================================================================================================================================+
   | admin_state_up        | No              | Boolean         | Specifies the administrative status of the certificate.                                                                                                                                                                                          |
   |                       |                 |                 |                                                                                                                                                                                                                                                  |
   |                       |                 |                 | This parameter is unsupported. Please do not use it.                                                                                                                                                                                             |
   +-----------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | certificate           | Yes             | String          | Specifies the body of the certificate required by HTTPS listeners. The value must be PEM encoded.                                                                                                                                                |
   |                       |                 |                 |                                                                                                                                                                                                                                                  |
   |                       |                 |                 | Maximum 65,536 character length is allowed, supports certificate chains with a maximum of 11 layers (including certificates and certificate chains).                                                                                             |
   +-----------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | description           | No              | String          | Provides supplementary information about the certificate.                                                                                                                                                                                        |
   |                       |                 |                 |                                                                                                                                                                                                                                                  |
   |                       |                 |                 | Minimum: **0**                                                                                                                                                                                                                                   |
   |                       |                 |                 |                                                                                                                                                                                                                                                  |
   |                       |                 |                 | Maximum: **255**                                                                                                                                                                                                                                 |
   +-----------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | domain                | No              | String          | Specifies the domain names used by the server certificate. This parameter will take effect only when **type** is set to **server** and the default value is **""**.                                                                              |
   |                       |                 |                 |                                                                                                                                                                                                                                                  |
   |                       |                 |                 | -  The value can contain 0 to 1024 characters and consists of multiple common domain names or wildcard domain names separated by commas. A maximum of 30 domain names are allowed.                                                               |
   |                       |                 |                 |                                                                                                                                                                                                                                                  |
   |                       |                 |                 | -  A common domain name consists of several labels separated by periods (.). Each label can contain a maximum of 63 characters, including letters, digits, and hyphens (-), and must start and end with a letter or digit. Example: www.test.com |
   |                       |                 |                 |                                                                                                                                                                                                                                                  |
   |                       |                 |                 | -  A wildcard domain name is a domain name starts with an asterisk (``*``). Example: \*.test.com                                                                                                                                                 |
   |                       |                 |                 |                                                                                                                                                                                                                                                  |
   |                       |                 |                 | Default: **""**                                                                                                                                                                                                                                  |
   |                       |                 |                 |                                                                                                                                                                                                                                                  |
   |                       |                 |                 | Minimum: **0**                                                                                                                                                                                                                                   |
   |                       |                 |                 |                                                                                                                                                                                                                                                  |
   |                       |                 |                 | Maximum: **1024**                                                                                                                                                                                                                                |
   +-----------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | No              | String          | Specifies the certificate name.                                                                                                                                                                                                                  |
   |                       |                 |                 |                                                                                                                                                                                                                                                  |
   |                       |                 |                 | Minimum: **0**                                                                                                                                                                                                                                   |
   |                       |                 |                 |                                                                                                                                                                                                                                                  |
   |                       |                 |                 | Maximum: **255**                                                                                                                                                                                                                                 |
   +-----------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | private_key           | No              | String          | Specifies the private key of the certificate used by HTTPS listeners. The value can contain up to 8,192 PEM encoded characters.                                                                                                                  |
   |                       |                 |                 |                                                                                                                                                                                                                                                  |
   |                       |                 |                 | -  This parameter is valid and mandatory only when **type** is set to **server**.                                                                                                                                                                |
   |                       |                 |                 |                                                                                                                                                                                                                                                  |
   |                       |                 |                 | -  This parameter will be ignored even if **type** is set to **client**. The value must be PEM encoded and will not take effect.                                                                                                                 |
   +-----------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | project_id            | No              | String          | -  This parameter is valid and mandatory only when **type** is set to **server**.                                                                                                                                                                |
   |                       |                 |                 |                                                                                                                                                                                                                                                  |
   |                       |                 |                 | Minimum: **1**                                                                                                                                                                                                                                   |
   |                       |                 |                 |                                                                                                                                                                                                                                                  |
   |                       |                 |                 | Maximum: **32**                                                                                                                                                                                                                                  |
   +-----------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type                  | No              | String          | Specifies the certificate type.                                                                                                                                                                                                                  |
   |                       |                 |                 |                                                                                                                                                                                                                                                  |
   |                       |                 |                 | The value can be **server** or **client**. **server** indicates server certificates, and **client** indicates CA certificates. The default value is **server**.                                                                                  |
   +-----------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | enterprise_project_id | No              | String          | Specifies the ID of the enterprise project that the certificate belongs to.                                                                                                                                                                      |
   |                       |                 |                 |                                                                                                                                                                                                                                                  |
   |                       |                 |                 | This parameter is unsupported. Please do not use it.                                                                                                                                                                                             |
   +-----------------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Response Parameters
-------------------

**Status code: 201**

.. table:: **Table 5** Response body parameters

   +-------------+-----------------------------------------------------------------------------+-----------------------------------------------------------------+
   | Parameter   | Type                                                                        | Description                                                     |
   +=============+=============================================================================+=================================================================+
   | request_id  | String                                                                      | Specifies the request ID. The value is automatically generated. |
   +-------------+-----------------------------------------------------------------------------+-----------------------------------------------------------------+
   | certificate | :ref:`CertificateInfo <createcertificate__response_certificateinfo>` object | Specifies the certificate.                                      |
   +-------------+-----------------------------------------------------------------------------+-----------------------------------------------------------------+

.. _createcertificate__response_certificateinfo:

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
   | domain                | String                | Specifies the domain names used by the server certificate. This parameter will take effect only when **type** is set to **server**.                                                                                                              |
   |                       |                       |                                                                                                                                                                                                                                                  |
   |                       |                       | -  The value can contain 0 to 1024 characters and consists of multiple common domain names or wildcard domain names separated by commas. A maximum of 30 domain names are allowed.                                                               |
   |                       |                       |                                                                                                                                                                                                                                                  |
   |                       |                       | -  A common domain name consists of several labels separated by periods (.). Each label can contain a maximum of 63 characters, including letters, digits, and hyphens (-), and must start and end with a letter or digit. Example: www.test.com |
   |                       |                       |                                                                                                                                                                                                                                                  |
   |                       |                       | -  A wildcard domain name is a domain name starts with an asterisk (``*``). Example: \*.test.com                                                                                                                                                 |
   |                       |                       |                                                                                                                                                                                                                                                  |
   |                       |                       | Minimum: **1**                                                                                                                                                                                                                                   |
   |                       |                       |                                                                                                                                                                                                                                                  |
   |                       |                       | Maximum: **1024**                                                                                                                                                                                                                                |
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
   |                       |                       |                                                                                                                                                                                                                                                  |
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

Creating a server certificate

.. code-block:: text

   POST https://{elb_endponit}/v3/{project_id}/elb/certificates

   {
     "certificate" : {
       "name" : "My Certificate",
       "type" : "server",
       "private_key" : "-----BEGIN PRIVATE KEY-----\nMIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQDQVAbOLe5xNf4M\n253Wn9vhdUzojetjv4J+B7kYwsMhRcgdcJ8KCnX1nfzTvI2ksXlTQ2o9BkpStnPe\ntB4s32ZiJRMlk+61iUUMNsHwK2WBX57JT3JgmyVbH8GbmRY0+H3sH1i72luna7rM\nMD30gLh6QoP3cq7PGWcuZKV7hjd1tjCTQukwMvqV8Icq39buNpIgDOWzEP5AzqXt\nCOFYn6RTH5SRug4hKNN7sT1eYMslHu7wtEBDKVgrLjOCe/W2f8rLT1zEsoAW2Chl\nZAPYUBkl/0XuTWRg3CohPPcI+UtlRSfvLDeeQ460swjbwgS/RbJh3sIwlCRLU08k\nEo04Z9H/AgMBAAECggEAEIeaQqHCWZk/HyYN0Am/GJSGFa2tD60SXY2fUieh8/Hl\nfvCArftGgMaYWPSNCJRMXB7tPwpQu19esjz4Z/cR2Je4fTLPrffGUsHFgZjv5OQB\nZVe4a5Hj1OcgJYhwCqPs2d9i2wToYNBbcfgh8lSETq8YaXngBO6vES9LMhHkNKKr\nciu9YkInNEHu6uRJ5g/eGGX3KQynTvVIhnOVGAJvjTXcoU6fm7gYdHAD6jk9lc9M\nEGpfYI6AdHIwFZcT/RNAxhP82lg2gUJSgAu66FfDjMwQXKbafKdP3zq4Up8a7Ale\nkrguPtfV1vWklg+bUFhgGaiAEYTpAUN9t2DVIiijgQKBgQDnYMMsaF0r557CM1CT\nXUqgCZo8MKeV2jf2drlxRRwRl33SksQbzAQ/qrLdT7GP3sCGqvkxWY2FPdFYf8kx\nGcCeZPcIeZYCQAM41pjtsaM8tVbLWVR8UtGBuQoPSph7JNF3Tm/JH/fbwjpjP7dt\nJ7n8EzkRUNE6aIMHOFEeych/PQKBgQDmf1bMogx63rTcwQ0PEZ9Vt7mTgKYK4aLr\niWgTWHXPZxUQaYhpjXo6+lMI6DpExiDgBAkMzJGIvS7yQiYWU+wthAr9urbWYdGZ\nlS6VjoTkF6r7VZoILXX0fbuXh6lm8K8IQRfBpJff56p9phMwaBpDNDrfpHB5utBU\nxs40yIdp6wKBgQC69Cp/xUwTX7GdxQzEJctYiKnBHKcspAg38zJf3bGSXU/jR4eB\n1lVQhELGI9CbKSdzKM71GyEImix/T7FnJSHIWlho1qVo6AQyduNWnAQD15pr8KAd\nXGXAZZ1FQcb3KYa+2fflERmazdOTwjYZ0tGqZnXkEeMdSLkmqlCRigWhGQKBgDak\n/735uP20KKqhNehZpC2dJei7OiIgRhCS/dKASUXHSW4fptBnUxACYocdDxtY4Vha\nfI7FPMdvGl8ioYbvlHFh+X0Xs9r1S8yeWnHoXMb6eXWmYKMJrAoveLa+2cFm1Agf\n7nLhA4R4lqm9IpV6SKegDUkR4fxp9pPyodZPqBLLAoGBAJkD4wHW54Pwd4Ctfk9o\njHjWB7pQlUYpTZO9dm+4fpCMn9Okf43AE2yAOaAP94GdzdDJkxfciXKcsYr9IIuk\nfaoXgjKR7p1zERiWZuFF63SB4aiyX1H7IX0MwHDZQO38a5gZaOm/BUlGKMWXzuEd\n3fy+1rCUwzOp9LSjtJYf4ege\n-----END PRIVATE KEY-----",
       "certificate" : "-----BEGIN CERTIFICATE-----\nMIIC4TCCAcmgAwIBAgICEREwDQYJKoZIhvcNAQELBQAwFzEVMBMGA1UEAxMMTXlD\nb21wYW55IENBMB4XDTE4MDcwMjEzMjU0N1oXDTQ1MTExNzEzMjU0N1owFDESMBAG\nA1UEAwwJbG9jYWxob3N0MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA\n0FQGzi3ucTX+DNud1p/b4XVM6I3rY7+Cfge5GMLDIUXIHXCfCgp19Z3807yNpLF5\nU0NqPQZKUrZz3rQeLN9mYiUTJZPutYlFDDbB8CtlgV+eyU9yYJslWx/Bm5kWNPh9\n7B9Yu9pbp2u6zDA99IC4ekKD93KuzxlnLmSle4Y3dbYwk0LpMDL6lfCHKt/W7jaS\nIAzlsxD+QM6l7QjhWJ+kUx+UkboOISjTe7E9XmDLJR7u8LRAQylYKy4zgnv1tn/K\ny09cxLKAFtgoZWQD2FAZJf9F7k1kYNwqITz3CPlLZUUn7yw3nkOOtLMI28IEv0Wy\nYd7CMJQkS1NPJBKNOGfR/wIDAQABozowODAhBgNVHREEGjAYggpkb21haW4uY29t\nhwQKuUvJhwR/AAABMBMGA1UdJQQMMAoGCCsGAQUFBwMBMA0GCSqGSIb3DQEBCwUA\nA4IBAQA8lMQJxaTey7EjXtRLSVlEAMftAQPG6jijNQuvIBQYUDauDT4W2XUZ5wAn\njiOyQ83va672K1G9s8n6xlH+xwwdSNnozaKzC87vwSeZKIOdl9I5I98TGKI6OoDa\nezmzCwQYtHBMVQ4c7Ml8554Ft1mWSt4dMAK2rzNYjvPRLYlzp1HMnI6hkjPk4PCZ\nwKnha0dlScati9CCt3UzXSNJOSLalKdHErH08Iqd+1BchScxCfk0xNITn1HZZGmI\n+vbmunok3A2lucI14rnsrcbkGYqxGikySN6B2cRLBDK4Y3wChiW6NVYtVqcx5/mZ\niYsGDVN+9QBd0eYUHce+77s96i3I\n-----END CERTIFICATE-----"
     }
   }

Example Responses
-----------------

**Status code: 201**

Normal response to POST requests.

.. code-block::

   {
     "certificate" : {
       "private_key" : "-----BEGIN PRIVATE KEY-----MIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQDQVAbOLe5xNf4M253Wn9vhdUzojetjv4J+B7kYwsMhRcgdcJ8KCnX1nfzTvI2ksXlTQ2o9BkpStnPetB4s32ZiJRMlk+61iUUMNsHwK2WBX57JT3JgmyVbH8GbmRY0+H3sH1i72luna7rMMD30gLh6QoP3cq7PGWcuZKV7hjd1tjCTQukwMvqV8Icq39buNpIgDOWzEP5AzqXtCOFYn6RTH5SRug4hKNN7sT1eYMslHu7wtEBDKVgrLjOCe/W2f8rLT1zEsoAW2ChlZAPYUBkl/0XuTWRg3CohPPcI+UtlRSfvLDeeQ460swjbwgS/RbJh3sIwlCRLU08kEo04Z9H/AgMBAAECggEAEIeaQqHCWZk/HyYN0Am/GJSGFa2tD60SXY2fUieh8/HlfvCArftGgMaYWPSNCJRMXB7tPwpQu19esjz4Z/cR2Je4fTLPrffGUsHFgZjv5OQBZVe4a5Hj1OcgJYhwCqPs2d9i2wToYNBbcfgh8lSETq8YaXngBO6vES9LMhHkNKKrciu9YkInNEHu6uRJ5g/eGGX3KQynTvVIhnOVGAJvjTXcoU6fm7gYdHAD6jk9lc9MEGpfYI6AdHIwFZcT/RNAxhP82lg2gUJSgAu66FfDjMwQXKbafKdP3zq4Up8a7AlekrguPtfV1vWklg+bUFhgGaiAEYTpAUN9t2DVIiijgQKBgQDnYMMsaF0r557CM1CTXUqgCZo8MKeV2jf2drlxRRwRl33SksQbzAQ/qrLdT7GP3sCGqvkxWY2FPdFYf8kxGcCeZPcIeZYCQAM41pjtsaM8tVbLWVR8UtGBuQoPSph7JNF3Tm/JH/fbwjpjP7dtJ7n8EzkRUNE6aIMHOFEeych/PQKBgQDmf1bMogx63rTcwQ0PEZ9Vt7mTgKYK4aLriWgTWHXPZxUQaYhpjXo6+lMI6DpExiDgBAkMzJGIvS7yQiYWU+wthAr9urbWYdGZlS6VjoTkF6r7VZoILXX0fbuXh6lm8K8IQRfBpJff56p9phMwaBpDNDrfpHB5utBUxs40yIdp6wKBgQC69Cp/xUwTX7GdxQzEJctYiKnBHKcspAg38zJf3bGSXU/jR4eB1lVQhELGI9CbKSdzKM71GyEImix/T7FnJSHIWlho1qVo6AQyduNWnAQD15pr8KAdXGXAZZ1FQcb3KYa+2fflERmazdOTwjYZ0tGqZnXkEeMdSLkmqlCRigWhGQKBgDak/735uP20KKqhNehZpC2dJei7OiIgRhCS/dKASUXHSW4fptBnUxACYocdDxtY4VhafI7FPMdvGl8ioYbvlHFh+X0Xs9r1S8yeWnHoXMb6eXWmYKMJrAoveLa+2cFm1Agf7nLhA4R4lqm9IpV6SKegDUkR4fxp9pPyodZPqBLLAoGBAJkD4wHW54Pwd4Ctfk9ojHjWB7pQlUYpTZO9dm+4fpCMn9Okf43AE2yAOaAP94GdzdDJkxfciXKcsYr9IIukfaoXgjKR7p1zERiWZuFF63SB4aiyX1H7IX0MwHDZQO38a5gZaOm/BUlGKMWXzuEd3fy+1rCUwzOp9LSjtJYf4ege-----END PRIVATE KEY-----",
       "description" : "",
       "domain" : null,
       "created_at" : "2019-03-31T22:23:51Z",
       "expire_time" : "2045-11-17T13:25:47Z",
       "id" : "233a325e5e3e4ce8beeb320aa714cc12",
       "name" : "My Certificate",
       "certificate" : "-----BEGIN CERTIFICATE-----MIIC4TCCAcmgAwIBAgICEREwDQYJKoZIhvcNAQELBQAwFzEVMBMGA1UEAxMMTXlDb21wYW55IENBMB4XDTE4MDcwMjEzMjU0N1oXDTQ1MTExNzEzMjU0N1owFDESMBAGA1UEAwwJbG9jYWxob3N0MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA0FQGzi3ucTX+DNud1p/b4XVM6I3rY7+Cfge5GMLDIUXIHXCfCgp19Z3807yNpLF5U0NqPQZKUrZz3rQeLN9mYiUTJZPutYlFDDbB8CtlgV+eyU9yYJslWx/Bm5kWNPh97B9Yu9pbp2u6zDA99IC4ekKD93KuzxlnLmSle4Y3dbYwk0LpMDL6lfCHKt/W7jaSIAzlsxD+QM6l7QjhWJ+kUx+UkboOISjTe7E9XmDLJR7u8LRAQylYKy4zgnv1tn/Ky09cxLKAFtgoZWQD2FAZJf9F7k1kYNwqITz3CPlLZUUn7yw3nkOOtLMI28IEv0WyYd7CMJQkS1NPJBKNOGfR/wIDAQABozowODAhBgNVHREEGjAYggpkb21haW4uY29thwQKuUvJhwR/AAABMBMGA1UdJQQMMAoGCCsGAQUFBwMBMA0GCSqGSIb3DQEBCwUAA4IBAQA8lMQJxaTey7EjXtRLSVlEAMftAQPG6jijNQuvIBQYUDauDT4W2XUZ5wAnjiOyQ83va672K1G9s8n6xlH+xwwdSNnozaKzC87vwSeZKIOdl9I5I98TGKI6OoDaezmzCwQYtHBMVQ4c7Ml8554Ft1mWSt4dMAK2rzNYjvPRLYlzp1HMnI6hkjPk4PCZwKnha0dlScati9CCt3UzXSNJOSLalKdHErH08Iqd+1BchScxCfk0xNITn1HZZGmI+vbmunok3A2lucI14rnsrcbkGYqxGikySN6B2cRLBDK4Y3wChiW6NVYtVqcx5/mZiYsGDVN+9QBd0eYUHce+77s96i3I-----END CERTIFICATE-----",
       "admin_state_up" : true,
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "updated_at" : "2019-03-31T23:26:49Z",
       "type" : "server"
     },
     "request_id" : "98414965-856c-4be3-8a33-3e08432a222e"
   }

Status Codes
------------

=========== =================================
Status Code Description
=========== =================================
201         Normal response to POST requests.
=========== =================================

Error Codes
-----------

See :ref:`Error Codes <errorcode>`.
