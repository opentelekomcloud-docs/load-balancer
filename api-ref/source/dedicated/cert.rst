===========
Certificate
===========

Creating a Certificate
======================

Function
^^^^^^^^

This API is used to create an SSL certificate.

URI
^^^

POST /v3/{project_id}/elb/certificates

.. table:: **Table 1** Path parameters

   ========== ========= ====== ============================================
   Parameter  Mandatory Type   Description
   ========== ========= ====== ============================================
   project_id Yes       String Specifies the project ID of the certificate.
   ========== ========= ====== ============================================

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

.. table:: **Table 3** Request body parameters

   +-------------+-----------+--------------------+----------------------------+
   | Parameter   | Mandatory | Type               | Description                |
   +=============+===========+====================+============================+
   | certificate | Yes       | :ref:`dcl_` object | Specifies the certificate. |
   +-------------+-----------+--------------------+----------------------------+

.. _dcl_:
.. table:: **Table 4** CreateCertificateOption

   +-----------------------+-----------+---------+-----------------------------+
   | Parameter             | Mandatory | Type    | Description                 |
   +=======================+===========+=========+=============================+
   | admin_state_up        | No        | Boolean | Specifies the               |
   |                       |           |         | administrative status of    |
   |                       |           |         | the certificate.            |
   |                       |           |         |                             |
   |                       |           |         | This parameter is           |
   |                       |           |         | unsupported. Please do not  |
   |                       |           |         | use it.                     |
   |                       |           |         |                             |
   |                       |           |         | Default: **true**           |
   +-----------------------+-----------+---------+-----------------------------+
   | certificate           | Yes       | String  | Specifies the private key   |
   |                       |           |         | of the certificate. The     |
   |                       |           |         | value must be PEM encoded.  |
   +-----------------------+-----------+---------+-----------------------------+
   | description           | No        | String  | Provides supplementary      |
   |                       |           |         | information about the       |
   |                       |           |         | certificate.                |
   |                       |           |         |                             |
   |                       |           |         | Minimum: **0**              |
   |                       |           |         |                             |
   |                       |           |         | Maximum: **255**            |
   +-----------------------+-----------+---------+-----------------------------+
   | domain                | No        | String  | Specifies the domain names  |
   |                       |           |         | used by the server          |
   |                       |           |         | certificate.                |
   |                       |           |         |                             |
   |                       |           |         | -  This parameter will take |
   |                       |           |         |    effect only when         |
   |                       |           |         |    **type** is set to       |
   |                       |           |         |    **server**, and its      |
   |                       |           |         |    default value is **""**. |
   |                       |           |         |                             |
   |                       |           |         | -  This parameter will not  |
   |                       |           |         |    take effect even if it   |
   |                       |           |         |    is passed and **type**   |
   |                       |           |         |    is set to **client**.    |
   |                       |           |         |    However, domain names    |
   |                       |           |         |    will still be verified.  |
   |                       |           |         |                             |
   |                       |           |         | Note:                       |
   |                       |           |         |                             |
   |                       |           |         | -  The value can contain 0  |
   |                       |           |         |    to 1024 characters and   |
   |                       |           |         |    consists of multiple     |
   |                       |           |         |    common domain names or   |
   |                       |           |         |    wildcard domain names    |
   |                       |           |         |    separated by commas. A   |
   |                       |           |         |    maximum of 30 domain     |
   |                       |           |         |    names are allowed.       |
   |                       |           |         |                             |
   |                       |           |         | -  A common domain name     |
   |                       |           |         |    consists of several      |
   |                       |           |         |    labels separated by      |
   |                       |           |         |    periods (.). Each label  |
   |                       |           |         |    can contain a maximum of |
   |                       |           |         |    63 characters, including |
   |                       |           |         |    letters, digits, and     |
   |                       |           |         |    hyphens (-), and must    |
   |                       |           |         |    start and end with a     |
   |                       |           |         |    letter or digit.         |
   |                       |           |         |    Example: www.test.com    |
   |                       |           |         |                             |
   |                       |           |         | -  A wildcard domain name   |
   |                       |           |         |    is a domain name starts  |
   |                       |           |         |    with an asterisk (*).    |
   |                       |           |         |    Example: \*.test.com     |
   +-----------------------+-----------+---------+-----------------------------+
   | name                  | No        | String  | Specifies the certificate   |
   |                       |           |         | name. Only letters, digits, |
   |                       |           |         | underscores, and hyphens    |
   |                       |           |         | are allowed.                |
   |                       |           |         |                             |
   |                       |           |         | Minimum: **0**              |
   |                       |           |         |                             |
   |                       |           |         | Maximum: **255**            |
   +-----------------------+-----------+---------+-----------------------------+
   | private_key           | No        | String  | Specifies the private key   |
   |                       |           |         | of the server certificate.  |
   |                       |           |         | The value must be PEM       |
   |                       |           |         | encoded.                    |
   |                       |           |         |                             |
   |                       |           |         | -  This parameter will be   |
   |                       |           |         |    ignored if **type** is   |
   |                       |           |         |    set to **client**. A CA  |
   |                       |           |         |    server can still be      |
   |                       |           |         |    created and used         |
   |                       |           |         |    normally. This parameter |
   |                       |           |         |    will be left blank even  |
   |                       |           |         |    if you enter a private   |
   |                       |           |         |    key that is not PEM      |
   |                       |           |         |    encoded.                 |
   |                       |           |         |                             |
   |                       |           |         | -  This parameter is valid  |
   |                       |           |         |    and mandatory only when  |
   |                       |           |         |    **type** is set to       |
   |                       |           |         |    **server**. If you enter |
   |                       |           |         |    an invalid private key,  |
   |                       |           |         |    an error is returned.    |
   +-----------------------+-----------+---------+-----------------------------+
   | project_id            | No        | String  | Specifies the ID of the     |
   |                       |           |         | project where the           |
   |                       |           |         | certificate is used.        |
   |                       |           |         |                             |
   |                       |           |         | Minimum: **1**              |
   |                       |           |         |                             |
   |                       |           |         | Maximum: **32**             |
   +-----------------------+-----------+---------+-----------------------------+
   | type                  | No        | String  | Specifies the certificate   |
   |                       |           |         | type.                       |
   |                       |           |         |                             |
   |                       |           |         | The value can be **server** |
   |                       |           |         | or **client**. **server**   |
   |                       |           |         | indicates server            |
   |                       |           |         | certificates, and           |
   |                       |           |         | **client** indicates CA     |
   |                       |           |         | certificates. The default   |
   |                       |           |         | value is **server**.        |
   +-----------------------+-----------+---------+-----------------------------+
   | enterprise_project_id | No        | String  | Specifies the enterprise    |
   |                       |           |         | project ID. The value       |
   |                       |           |         | cannot be **""**, **"0"**,  |
   |                       |           |         | or the ID of an enterprise  |
   |                       |           |         | project that does not       |
   |                       |           |         | exist.                      |
   |                       |           |         |                             |
   |                       |           |         | If this parameter is not    |
   |                       |           |         | passed during resource      |
   |                       |           |         | creation, the resource      |
   |                       |           |         | belongs to the default      |
   |                       |           |         | enterprise project.         |
   |                       |           |         |                             |
   |                       |           |         | This parameter is           |
   |                       |           |         | unsupported. Please do not  |
   |                       |           |         | use it.                     |
   +-----------------------+-----------+---------+-----------------------------+

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 201**

.. table:: **Table 5** Response body parameters

   +-------------+----------------------+----------------------------------------+
   | Parameter   | Type                 | Description                            |
   +=============+======================+========================================+
   | request_id  | String               | Specifies the request ID. The value is |
   |             |                      | automatically generated.               |
   +-------------+----------------------+----------------------------------------+
   | certificate | :ref:`dcl_cr` object | Specifies the certificate.             |
   +-------------+----------------------+----------------------------------------+

.. _dcl_cr:
.. table:: **Table 6** CertificateInfo

   +----------------+---------+---------------------------------------+
   | Parameter      | Type    | Description                           |
   +================+=========+=======================================+
   | admin_state_up | Boolean | Specifies the administrative status   |
   |                |         | of the certificate.                   |
   |                |         |                                       |
   |                |         | This parameter is unsupported. Please |
   |                |         | do not use it.                        |
   +----------------+---------+---------------------------------------+
   | certificate    | String  | Specifies the private key of the      |
   |                |         | certificate. The value must be PEM    |
   |                |         | encoded.                              |
   +----------------+---------+---------------------------------------+
   | description    | String  | Provides supplementary information    |
   |                |         | about the certificate.                |
   |                |         |                                       |
   |                |         | Minimum: **1**                        |
   |                |         |                                       |
   |                |         | Maximum: **255**                      |
   +----------------+---------+---------------------------------------+
   | domain         | String  | Specifies the domain names used by    |
   |                |         | the server certificate.               |
   |                |         |                                       |
   |                |         | -  This parameter will take effect    |
   |                |         |    only when **type** is set to       |
   |                |         |    **server**, and its default value  |
   |                |         |    is **""**.                         |
   |                |         |                                       |
   |                |         | -  This parameter will not take       |
   |                |         |    effect even if it is passed and    |
   |                |         |    **type** is set to **client**.     |
   |                |         |    However, domain names will still   |
   |                |         |    be verified.                       |
   |                |         |                                       |
   |                |         | Note:                                 |
   |                |         |                                       |
   |                |         | -  The value can contain 0 to 1024    |
   |                |         |    characters and consists of         |
   |                |         |    multiple common domain names or    |
   |                |         |    wildcard domain names separated by |
   |                |         |    commas. A maximum of 30 domain     |
   |                |         |    names are allowed.                 |
   |                |         |                                       |
   |                |         | -  A common domain name consists of   |
   |                |         |    several labels separated by        |
   |                |         |    periods (.). Each label can        |
   |                |         |    contain a maximum of 63            |
   |                |         |    characters, including letters,     |
   |                |         |    digits, and hyphens (-), and must  |
   |                |         |    start and end with a letter or     |
   |                |         |    digit. Example: www.test.com       |
   |                |         |                                       |
   |                |         | -  A wildcard domain name is a domain |
   |                |         |    name starts with an asterisk (*).  |
   |                |         |    Example: \*.test.com               |
   |                |         |                                       |
   |                |         | Minimum: **1**                        |
   |                |         |                                       |
   |                |         | Maximum: **1024**                     |
   +----------------+---------+---------------------------------------+
   | id             | String  | Specifies a certificate ID.           |
   +----------------+---------+---------------------------------------+
   | name           | String  | Specifies the certificate name.       |
   |                |         |                                       |
   |                |         | Minimum: **1**                        |
   |                |         |                                       |
   |                |         | Maximum: **255**                      |
   +----------------+---------+---------------------------------------+
   | private_key    | String  | Specifies the private key of the      |
   |                |         | server certificate. The value must be |
   |                |         | PEM encoded.                          |
   |                |         |                                       |
   |                |         | -  This parameter will be ignored if  |
   |                |         |    **type** is set to **client**. A   |
   |                |         |    CA server can still be created and |
   |                |         |    used normally. This parameter will |
   |                |         |    be left blank even if you enter a  |
   |                |         |    private key that is not PEM        |
   |                |         |    encoded.                           |
   |                |         |                                       |
   |                |         | -  This parameter is valid and        |
   |                |         |    mandatory only when **type** is    |
   |                |         |    set to **server**. If you enter an |
   |                |         |    invalid private key, an error is   |
   |                |         |    returned.                          |
   +----------------+---------+---------------------------------------+
   | type           | String  | Specifies the certificate type. The   |
   |                |         | value can be **server** or            |
   |                |         | **client**. **server** indicates      |
   |                |         | server certificates, and **client**   |
   |                |         | indicates CA certificates. The        |
   |                |         | default value is **server**.          |
   +----------------+---------+---------------------------------------+
   | created_at     | String  | Specifies the time when the           |
   |                |         | certificate was created.              |
   +----------------+---------+---------------------------------------+
   | updated_at     | String  | Specifies the time when the           |
   |                |         | certificate was updated.              |
   +----------------+---------+---------------------------------------+
   | expire_time    | String  | Specifies the time when the           |
   |                |         | certificate expires.                  |
   +----------------+---------+---------------------------------------+
   | project_id     | String  | Specifies the project ID.             |
   +----------------+---------+---------------------------------------+

Example Requests
^^^^^^^^^^^^^^^^

.. code::

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
^^^^^^^^^^^^^^^^^

**Status code: 201**

Successful request.

.. code::

   {
     "certificate" : {
       "id" : "233a325e5e3e4ce8beeb320aa714cc12",
       "name" : "My Certificate",
       "description" : "",
       "admin_state_up" : true,
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "updated_at" : "2019-03-31T23:26:49Z",
       "type" : "server",
       "created_at" : "2019-03-31T22:23:51Z",
       "expire_time" : "2045-11-17T13:25:47Z",
       "private_key" : "-----BEGIN PRIVATE KEY-----\nMIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQDQVAbOLe5xNf4M\n253Wn9vhdUzojetjv4J+B7kYwsMhRcgdcJ8KCnX1nfzTvI2ksXlTQ2o9BkpStnPe\ntB4s32ZiJRMlk+61iUUMNsHwK2WBX57JT3JgmyVbH8GbmRY0+H3sH1i72luna7rM\nMD30gLh6QoP3cq7PGWcuZKV7hjd1tjCTQukwMvqV8Icq39buNpIgDOWzEP5AzqXt\nCOFYn6RTH5SRug4hKNN7sT1eYMslHu7wtEBDKVgrLjOCe/W2f8rLT1zEsoAW2Chl\nZAPYUBkl/0XuTWRg3CohPPcI+UtlRSfvLDeeQ460swjbwgS/RbJh3sIwlCRLU08k\nEo04Z9H/AgMBAAECggEAEIeaQqHCWZk/HyYN0Am/GJSGFa2tD60SXY2fUieh8/Hl\nfvCArftGgMaYWPSNCJRMXB7tPwpQu19esjz4Z/cR2Je4fTLPrffGUsHFgZjv5OQB\nZVe4a5Hj1OcgJYhwCqPs2d9i2wToYNBbcfgh8lSETq8YaXngBO6vES9LMhHkNKKr\nciu9YkInNEHu6uRJ5g/eGGX3KQynTvVIhnOVGAJvjTXcoU6fm7gYdHAD6jk9lc9M\nEGpfYI6AdHIwFZcT/RNAxhP82lg2gUJSgAu66FfDjMwQXKbafKdP3zq4Up8a7Ale\nkrguPtfV1vWklg+bUFhgGaiAEYTpAUN9t2DVIiijgQKBgQDnYMMsaF0r557CM1CT\nXUqgCZo8MKeV2jf2drlxRRwRl33SksQbzAQ/qrLdT7GP3sCGqvkxWY2FPdFYf8kx\nGcCeZPcIeZYCQAM41pjtsaM8tVbLWVR8UtGBuQoPSph7JNF3Tm/JH/fbwjpjP7dt\nJ7n8EzkRUNE6aIMHOFEeych/PQKBgQDmf1bMogx63rTcwQ0PEZ9Vt7mTgKYK4aLr\niWgTWHXPZxUQaYhpjXo6+lMI6DpExiDgBAkMzJGIvS7yQiYWU+wthAr9urbWYdGZ\nlS6VjoTkF6r7VZoILXX0fbuXh6lm8K8IQRfBpJff56p9phMwaBpDNDrfpHB5utBU\nxs40yIdp6wKBgQC69Cp/xUwTX7GdxQzEJctYiKnBHKcspAg38zJf3bGSXU/jR4eB\n1lVQhELGI9CbKSdzKM71GyEImix/T7FnJSHIWlho1qVo6AQyduNWnAQD15pr8KAd\nXGXAZZ1FQcb3KYa+2fflERmazdOTwjYZ0tGqZnXkEeMdSLkmqlCRigWhGQKBgDak\n/735uP20KKqhNehZpC2dJei7OiIgRhCS/dKASUXHSW4fptBnUxACYocdDxtY4Vha\nfI7FPMdvGl8ioYbvlHFh+X0Xs9r1S8yeWnHoXMb6eXWmYKMJrAoveLa+2cFm1Agf\n7nLhA4R4lqm9IpV6SKegDUkR4fxp9pPyodZPqBLLAoGBAJkD4wHW54Pwd4Ctfk9o\njHjWB7pQlUYpTZO9dm+4fpCMn9Okf43AE2yAOaAP94GdzdDJkxfciXKcsYr9IIuk\nfaoXgjKR7p1zERiWZuFF63SB4aiyX1H7IX0MwHDZQO38a5gZaOm/BUlGKMWXzuEd\n3fy+1rCUwzOp9LSjtJYf4ege\n-----END PRIVATE KEY-----",
       "certificate" : "-----BEGIN CERTIFICATE-----\nMIIC4TCCAcmgAwIBAgICEREwDQYJKoZIhvcNAQELBQAwFzEVMBMGA1UEAxMMTXlD\nb21wYW55IENBMB4XDTE4MDcwMjEzMjU0N1oXDTQ1MTExNzEzMjU0N1owFDESMBAG\nA1UEAwwJbG9jYWxob3N0MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA\n0FQGzi3ucTX+DNud1p/b4XVM6I3rY7+Cfge5GMLDIUXIHXCfCgp19Z3807yNpLF5\nU0NqPQZKUrZz3rQeLN9mYiUTJZPutYlFDDbB8CtlgV+eyU9yYJslWx/Bm5kWNPh9\n7B9Yu9pbp2u6zDA99IC4ekKD93KuzxlnLmSle4Y3dbYwk0LpMDL6lfCHKt/W7jaS\nIAzlsxD+QM6l7QjhWJ+kUx+UkboOISjTe7E9XmDLJR7u8LRAQylYKy4zgnv1tn/K\ny09cxLKAFtgoZWQD2FAZJf9F7k1kYNwqITz3CPlLZUUn7yw3nkOOtLMI28IEv0Wy\nYd7CMJQkS1NPJBKNOGfR/wIDAQABozowODAhBgNVHREEGjAYggpkb21haW4uY29t\nhwQKuUvJhwR/AAABMBMGA1UdJQQMMAoGCCsGAQUFBwMBMA0GCSqGSIb3DQEBCwUA\nA4IBAQA8lMQJxaTey7EjXtRLSVlEAMftAQPG6jijNQuvIBQYUDauDT4W2XUZ5wAn\njiOyQ83va672K1G9s8n6xlH+xwwdSNnozaKzC87vwSeZKIOdl9I5I98TGKI6OoDa\nezmzCwQYtHBMVQ4c7Ml8554Ft1mWSt4dMAK2rzNYjvPRLYlzp1HMnI6hkjPk4PCZ\nwKnha0dlScati9CCt3UzXSNJOSLalKdHErH08Iqd+1BchScxCfk0xNITn1HZZGmI\n+vbmunok3A2lucI14rnsrcbkGYqxGikySN6B2cRLBDK4Y3wChiW6NVYtVqcx5/mZ\niYsGDVN+9QBd0eYUHce+77s96i3I\n-----END CERTIFICATE-----"
     },
     "request_id" : "98414965-856c-4be3-8a33-3e08432a222e"
   }

Status Codes
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
201         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Querying Certificates
=====================

Function
^^^^^^^^

This API is used to query all SSL certificates.

Constraints
^^^^^^^^^^^

Parameters **marker**, **limit**, and **page_reverse** are used for pagination
query.

Parameters **marker** and **page_reverse** take effect only when they are used
together with parameter **limit**.

URI
^^^

GET /v3/{project_id}/elb/certificates

.. table:: **Table 1** Path parameters

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =========================

.. table:: **Table 2** Query parameters

   +----------------+-----------+---------+-----------------------------+
   | Parameter      | Mandatory | Type    | Description                 |
   +================+===========+=========+=============================+
   | marker         | No        | String  | Specifies the ID of the     |
   |                |           |         | last record on the previous |
   |                |           |         | page.                       |
   |                |           |         |                             |
   |                |           |         | Note:                       |
   |                |           |         |                             |
   |                |           |         | -  This parameter must be   |
   |                |           |         |    used together with       |
   |                |           |         |    **limit**.               |
   |                |           |         |                             |
   |                |           |         | -  If this parameter is not |
   |                |           |         |    specified, the first     |
   |                |           |         |    page will be queried.    |
   |                |           |         |                             |
   |                |           |         | -  This parameter cannot be |
   |                |           |         |    left blank or set to an  |
   |                |           |         |    invalid ID.              |
   +----------------+-----------+---------+-----------------------------+
   | limit          | No        | Integer | Specifies the number of     |
   |                |           |         | records on each page.       |
   |                |           |         |                             |
   |                |           |         | Minimum: **0**              |
   |                |           |         |                             |
   |                |           |         | Maximum: **2000**           |
   +----------------+-----------+---------+-----------------------------+
   | page_reverse   | No        | Boolean | Specifies the page          |
   |                |           |         | direction. The value can be |
   |                |           |         | **true** or **false**, and  |
   |                |           |         | the default value is        |
   |                |           |         | **false**. The last page in |
   |                |           |         | the list requested with     |
   |                |           |         | **page_reverse** set to     |
   |                |           |         | **false** will not contain  |
   |                |           |         | the "next" link, and the    |
   |                |           |         | last page in the list       |
   |                |           |         | requested with              |
   |                |           |         | **page_reverse** set to     |
   |                |           |         | **true** will not contain   |
   |                |           |         | the "previous" link. This   |
   |                |           |         | parameter must be used      |
   |                |           |         | together with **limit**.    |
   +----------------+-----------+---------+-----------------------------+
   | id             | No        | Array   | Specifies a certificate ID. |
   |                |           |         |                             |
   |                |           |         | Multiple IDs can be queried |
   |                |           |         | in the format of            |
   |                |           |         | *id=xxx&id=xxx*.            |
   +----------------+-----------+---------+-----------------------------+
   | name           | No        | Array   | Specifies the certificate   |
   |                |           |         | name.                       |
   |                |           |         |                             |
   |                |           |         | Multiple names can be       |
   |                |           |         | queried in the format of    |
   |                |           |         | *name=xxx&name=xxx*.        |
   +----------------+-----------+---------+-----------------------------+
   | description    | No        | Array   | Provides supplementary      |
   |                |           |         | information about the       |
   |                |           |         | certificate.                |
   |                |           |         |                             |
   |                |           |         | Multiple descriptions can   |
   |                |           |         | be queried in the format of |
   |                |           |         | *descri                     |
   |                |           |         | ption=xxx&description=xxx*. |
   +----------------+-----------+---------+-----------------------------+
   | admin_state_up | No        | Boolean | Specifies the               |
   |                |           |         | administrative status of    |
   |                |           |         | the certificate.            |
   |                |           |         |                             |
   |                |           |         | This parameter is           |
   |                |           |         | unsupported. Please do not  |
   |                |           |         | use it.                     |
   +----------------+-----------+---------+-----------------------------+
   | domain         | No        | Array   | Specifies the domain names  |
   |                |           |         | used by the server          |
   |                |           |         | certificate. This parameter |
   |                |           |         | is available only when      |
   |                |           |         | **type** is set to          |
   |                |           |         | **server**.                 |
   |                |           |         |                             |
   |                |           |         | Multiple domain names can   |
   |                |           |         | be queried in the format of |
   |                |           |         | *domain=xxx&domain=xxx*.    |
   +----------------+-----------+---------+-----------------------------+
   | type           | No        | Array   | Specifies the certificate   |
   |                |           |         | type.                       |
   |                |           |         |                             |
   |                |           |         | The value can be **server** |
   |                |           |         | or **client**. **server**   |
   |                |           |         | indicates server            |
   |                |           |         | certificates, and           |
   |                |           |         | **client** indicates CA     |
   |                |           |         | certificates.               |
   |                |           |         |                             |
   |                |           |         | Multiple types can be       |
   |                |           |         | queried in the format of    |
   |                |           |         | *type=xxx&type=xxx*.        |
   +----------------+-----------+---------+-----------------------------+

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 3** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 200**

.. table:: **Table 4** Response body parameters

   +--------------+--------------------------------+----------------------------------------+
   | Parameter    | Type                           | Description                            |
   +==============+================================+========================================+
   | request_id   | String                         | Specifies the request ID. The value is |
   |              |                                | automatically generated.               |
   +--------------+--------------------------------+----------------------------------------+
   | page_info    | :ref:`dcl_pi` object           | Certificate pagination information     |
   +--------------+--------------------------------+----------------------------------------+
   | certificates | Array of :ref:`dcl_ci` objects | Lists the certificates.                |
   +--------------+--------------------------------+----------------------------------------+

.. _dcl_pi:
.. table:: **Table 5** PageInfo

   +-----------------+---------+----------------------------------------------------------------------------------------+
   | Parameter       | Type    | Description                                                                            |
   +=================+=========+========================================================================================+
   | previous_marker | String  | Specifies the ID of the first record in the pagination query result. This parameter    |
   |                 |         | will not be returned if no query result is returned.                                   |
   +-----------------+---------+----------------------------------------------------------------------------------------+
   | next_marker     | String  | Marks the start record on the next page in the pagination query result. This parameter |
   |                 |         | will not be returned if there is no next page.                                         |
   +-----------------+---------+----------------------------------------------------------------------------------------+
   | current_count   | Integer | Specifies the number of records.                                                       |
   +-----------------+---------+----------------------------------------------------------------------------------------+

.. _dcl_ci:
.. table:: **Table 6** CertificateInfo

   +----------------+---------+---------------------------------------+
   | Parameter      | Type    | Description                           |
   +================+=========+=======================================+
   | admin_state_up | Boolean | Specifies the administrative status   |
   |                |         | of the certificate.                   |
   |                |         |                                       |
   |                |         | This parameter is unsupported. Please |
   |                |         | do not use it.                        |
   +----------------+---------+---------------------------------------+
   | certificate    | String  | Specifies the private key of the      |
   |                |         | certificate. The value must be PEM    |
   |                |         | encoded.                              |
   +----------------+---------+---------------------------------------+
   | description    | String  | Provides supplementary information    |
   |                |         | about the certificate.                |
   |                |         |                                       |
   |                |         | Minimum: **1**                        |
   |                |         |                                       |
   |                |         | Maximum: **255**                      |
   +----------------+---------+---------------------------------------+
   | domain         | String  | Specifies the domain names used by    |
   |                |         | the server certificate.               |
   |                |         |                                       |
   |                |         | -  This parameter will take effect    |
   |                |         |    only when **type** is set to       |
   |                |         |    **server**, and its default value  |
   |                |         |    is **""**.                         |
   |                |         |                                       |
   |                |         | -  This parameter will not take       |
   |                |         |    effect even if it is passed and    |
   |                |         |    **type** is set to **client**.     |
   |                |         |    However, domain names will still   |
   |                |         |    be verified.                       |
   |                |         |                                       |
   |                |         | Note:                                 |
   |                |         |                                       |
   |                |         | -  The value can contain 0 to 1024    |
   |                |         |    characters and consists of         |
   |                |         |    multiple common domain names or    |
   |                |         |    wildcard domain names separated by |
   |                |         |    commas. A maximum of 30 domain     |
   |                |         |    names are allowed.                 |
   |                |         |                                       |
   |                |         | -  A common domain name consists of   |
   |                |         |    several labels separated by        |
   |                |         |    periods (.). Each label can        |
   |                |         |    contain a maximum of 63            |
   |                |         |    characters, including letters,     |
   |                |         |    digits, and hyphens (-), and must  |
   |                |         |    start and end with a letter or     |
   |                |         |    digit. Example: www.test.com       |
   |                |         |                                       |
   |                |         | -  A wildcard domain name is a domain |
   |                |         |    name starts with an asterisk (*).  |
   |                |         |    Example: \*.test.com               |
   |                |         |                                       |
   |                |         | Minimum: **1**                        |
   |                |         |                                       |
   |                |         | Maximum: **1024**                     |
   +----------------+---------+---------------------------------------+
   | id             | String  | Specifies a certificate ID.           |
   +----------------+---------+---------------------------------------+
   | name           | String  | Specifies the certificate name.       |
   |                |         |                                       |
   |                |         | Minimum: **1**                        |
   |                |         |                                       |
   |                |         | Maximum: **255**                      |
   +----------------+---------+---------------------------------------+
   | private_key    | String  | Specifies the private key of the      |
   |                |         | server certificate. The value must be |
   |                |         | PEM encoded.                          |
   |                |         |                                       |
   |                |         | -  This parameter will be ignored if  |
   |                |         |    **type** is set to **client**. A   |
   |                |         |    CA server can still be created and |
   |                |         |    used normally. This parameter will |
   |                |         |    be left blank even if you enter a  |
   |                |         |    private key that is not PEM        |
   |                |         |    encoded.                           |
   |                |         |                                       |
   |                |         | -  This parameter is valid and        |
   |                |         |    mandatory only when **type** is    |
   |                |         |    set to **server**. If you enter an |
   |                |         |    invalid private key, an error is   |
   |                |         |    returned.                          |
   +----------------+---------+---------------------------------------+
   | type           | String  | Specifies the certificate type. The   |
   |                |         | value can be **server** or            |
   |                |         | **client**. **server** indicates      |
   |                |         | server certificates, and **client**   |
   |                |         | indicates CA certificates. The        |
   |                |         | default value is **server**.          |
   +----------------+---------+---------------------------------------+
   | created_at     | String  | Specifies the time when the           |
   |                |         | certificate was created.              |
   +----------------+---------+---------------------------------------+
   | updated_at     | String  | Specifies the time when the           |
   |                |         | certificate was updated.              |
   +----------------+---------+---------------------------------------+
   | expire_time    | String  | Specifies the time when the           |
   |                |         | certificate expires.                  |
   +----------------+---------+---------------------------------------+
   | project_id     | String  | Specifies the project ID.             |
   +----------------+---------+---------------------------------------+

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   GET https://{elb_endpoint}/v3/{project_id}/elb/certificates

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

   {
     "certificates" : [ {
       "id" : "5494a835d88f40ff940554992f2f04d4",
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "name" : "https_certificatekkkk",
       "type" : "server",
       "description" : "description for certificatehhhh",
       "private_key" : "-----BEGIN PRIVATE KEY-----\nMIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQDQVAbOLe5xNf4M\n253Wn9vhdUzojetjv4J+B7kYwsMhRcgdcJ8KCnX1nfzTvI2ksXlTQ2o9BkpStnPe\ntB4s32ZiJRMlk+61iUUMNsHwK2WBX57JT3JgmyVbH8GbmRY0+H3sH1i72luna7rM\nMD30gLh6QoP3cq7PGWcuZKV7hjd1tjCTQukwMvqV8Icq39buNpIgDOWzEP5AzqXt\nCOFYn6RTH5SRug4hKNN7sT1eYMslHu7wtEBDKVgrLjOCe/W2f8rLT1zEsoAW2Chl\nZAPYUBkl/0XuTWRg3CohPPcI+UtlRSfvLDeeQ460swjbwgS/RbJh3sIwlCRLU08k\nEo04Z9H/AgMBAAECggEAEIeaQqHCWZk/HyYN0Am/GJSGFa2tD60SXY2fUieh8/Hl\nfvCArftGgMaYWPSNCJRMXB7tPwpQu19esjz4Z/cR2Je4fTLPrffGUsHFgZjv5OQB\nZVe4a5Hj1OcgJYhwCqPs2d9i2wToYNBbcfgh8lSETq8YaXngBO6vES9LMhHkNKKr\nciu9YkInNEHu6uRJ5g/eGGX3KQynTvVIhnOVGAJvjTXcoU6fm7gYdHAD6jk9lc9M\nEGpfYI6AdHIwFZcT/RNAxhP82lg2gUJSgAu66FfDjMwQXKbafKdP3zq4Up8a7Ale\nkrguPtfV1vWklg+bUFhgGaiAEYTpAUN9t2DVIiijgQKBgQDnYMMsaF0r557CM1CT\nXUqgCZo8MKeV2jf2drlxRRwRl33SksQbzAQ/qrLdT7GP3sCGqvkxWY2FPdFYf8kx\nGcCeZPcIeZYCQAM41pjtsaM8tVbLWVR8UtGBuQoPSph7JNF3Tm/JH/fbwjpjP7dt\nJ7n8EzkRUNE6aIMHOFEeych/PQKBgQDmf1bMogx63rTcwQ0PEZ9Vt7mTgKYK4aLr\niWgTWHXPZxUQaYhpjXo6+lMI6DpExiDgBAkMzJGIvS7yQiYWU+wthAr9urbWYdGZ\nlS6VjoTkF6r7VZoILXX0fbuXh6lm8K8IQRfBpJff56p9phMwaBpDNDrfpHB5utBU\nxs40yIdp6wKBgQC69Cp/xUwTX7GdxQzEJctYiKnBHKcspAg38zJf3bGSXU/jR4eB\n1lVQhELGI9CbKSdzKM71GyEImix/T7FnJSHIWlho1qVo6AQyduNWnAQD15pr8KAd\nXGXAZZ1FQcb3KYa+2fflERmazdOTwjYZ0tGqZnXkEeMdSLkmqlCRigWhGQKBgDak\n/735uP20KKqhNehZpC2dJei7OiIgRhCS/dKASUXHSW4fptBnUxACYocdDxtY4Vha\nfI7FPMdvGl8ioYbvlHFh+X0Xs9r1S8yeWnHoXMb6eXWmYKMJrAoveLa+2cFm1Agf\n7nLhA4R4lqm9IpV6SKegDUkR4fxp9pPyodZPqBLLAoGBAJkD4wHW54Pwd4Ctfk9o\njHjWB7pQlUYpTZO9dm+4fpCMn9Okf43AE2yAOaAP94GdzdDJkxfciXKcsYr9IIuk\nfaoXgjKR7p1zERiWZuFF63SB4aiyX1H7IX0MwHDZQO38a5gZaOm/BUlGKMWXzuEd\n3fy+1rCUwzOp9LSjtJYf4ege\n-----END PRIVATE KEY-----",
       "certificate" : "-----BEGIN CERTIFICATE-----\nMIIC4TCCAcmgAwIBAgICEREwDQYJKoZIhvcNAQELBQAwFzEVMBMGA1UEAxMMTXlD\nb21wYW55IENBMB4XDTE4MDcwMjEzMjU0N1oXDTQ1MTExNzEzMjU0N1owFDESMBAG\nA1UEAwwJbG9jYWxob3N0MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA\n0FQGzi3ucTX+DNud1p/b4XVM6I3rY7+Cfge5GMLDIUXIHXCfCgp19Z3807yNpLF5\nU0NqPQZKUrZz3rQeLN9mYiUTJZPutYlFDDbB8CtlgV+eyU9yYJslWx/Bm5kWNPh9\n7B9Yu9pbp2u6zDA99IC4ekKD93KuzxlnLmSle4Y3dbYwk0LpMDL6lfCHKt/W7jaS\nIAzlsxD+QM6l7QjhWJ+kUx+UkboOISjTe7E9XmDLJR7u8LRAQylYKy4zgnv1tn/K\ny09cxLKAFtgoZWQD2FAZJf9F7k1kYNwqITz3CPlLZUUn7yw3nkOOtLMI28IEv0Wy\nYd7CMJQkS1NPJBKNOGfR/wIDAQABozowODAhBgNVHREEGjAYggpkb21haW4uY29t\nhwQKuUvJhwR/AAABMBMGA1UdJQQMMAoGCCsGAQUFBwMBMA0GCSqGSIb3DQEBCwUA\nA4IBAQA8lMQJxaTey7EjXtRLSVlEAMftAQPG6jijNQuvIBQYUDauDT4W2XUZ5wAn\njiOyQ83va672K1G9s8n6xlH+xwwdSNnozaKzC87vwSeZKIOdl9I5I98TGKI6OoDa\nezmzCwQYtHBMVQ4c7Ml8554Ft1mWSt4dMAK2rzNYjvPRLYlzp1HMnI6hkjPk4PCZ\nwKnha0dlScati9CCt3UzXSNJOSLalKdHErH08Iqd+1BchScxCfk0xNITn1HZZGmI\n+vbmunok3A2lucI14rnsrcbkGYqxGikySN6B2cRLBDK4Y3wChiW6NVYtVqcx5/mZ\niYsGDVN+9QBd0eYUHce+77s96i3I\n-----END CERTIFICATE-----",
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
       "private_key" : "-----BEGIN PRIVATE KEY-----\nMIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQDQVAbOLe5xNf4M\n253Wn9vhdUzojetjv4J+B7kYwsMhRcgdcJ8KCnX1nfzTvI2ksXlTQ2o9BkpStnPe\ntB4s32ZiJRMlk+61iUUMNsHwK2WBX57JT3JgmyVbH8GbmRY0+H3sH1i72luna7rM\nMD30gLh6QoP3cq7PGWcuZKV7hjd1tjCTQukwMvqV8Icq39buNpIgDOWzEP5AzqXt\nCOFYn6RTH5SRug4hKNN7sT1eYMslHu7wtEBDKVgrLjOCe/W2f8rLT1zEsoAW2Chl\nZAPYUBkl/0XuTWRg3CohPPcI+UtlRSfvLDeeQ460swjbwgS/RbJh3sIwlCRLU08k\nEo04Z9H/AgMBAAECggEAEIeaQqHCWZk/HyYN0Am/GJSGFa2tD60SXY2fUieh8/Hl\nfvCArftGgMaYWPSNCJRMXB7tPwpQu19esjz4Z/cR2Je4fTLPrffGUsHFgZjv5OQB\nZVe4a5Hj1OcgJYhwCqPs2d9i2wToYNBbcfgh8lSETq8YaXngBO6vES9LMhHkNKKr\nciu9YkInNEHu6uRJ5g/eGGX3KQynTvVIhnOVGAJvjTXcoU6fm7gYdHAD6jk9lc9M\nEGpfYI6AdHIwFZcT/RNAxhP82lg2gUJSgAu66FfDjMwQXKbafKdP3zq4Up8a7Ale\nkrguPtfV1vWklg+bUFhgGaiAEYTpAUN9t2DVIiijgQKBgQDnYMMsaF0r557CM1CT\nXUqgCZo8MKeV2jf2drlxRRwRl33SksQbzAQ/qrLdT7GP3sCGqvkxWY2FPdFYf8kx\nGcCeZPcIeZYCQAM41pjtsaM8tVbLWVR8UtGBuQoPSph7JNF3Tm/JH/fbwjpjP7dt\nJ7n8EzkRUNE6aIMHOFEeych/PQKBgQDmf1bMogx63rTcwQ0PEZ9Vt7mTgKYK4aLr\niWgTWHXPZxUQaYhpjXo6+lMI6DpExiDgBAkMzJGIvS7yQiYWU+wthAr9urbWYdGZ\nlS6VjoTkF6r7VZoILXX0fbuXh6lm8K8IQRfBpJff56p9phMwaBpDNDrfpHB5utBU\nxs40yIdp6wKBgQC69Cp/xUwTX7GdxQzEJctYiKnBHKcspAg38zJf3bGSXU/jR4eB\n1lVQhELGI9CbKSdzKM71GyEImix/T7FnJSHIWlho1qVo6AQyduNWnAQD15pr8KAd\nXGXAZZ1FQcb3KYa+2fflERmazdOTwjYZ0tGqZnXkEeMdSLkmqlCRigWhGQKBgDak\n/735uP20KKqhNehZpC2dJei7OiIgRhCS/dKASUXHSW4fptBnUxACYocdDxtY4Vha\nfI7FPMdvGl8ioYbvlHFh+X0Xs9r1S8yeWnHoXMb6eXWmYKMJrAoveLa+2cFm1Agf\n7nLhA4R4lqm9IpV6SKegDUkR4fxp9pPyodZPqBLLAoGBAJkD4wHW54Pwd4Ctfk9o\njHjWB7pQlUYpTZO9dm+4fpCMn9Okf43AE2yAOaAP94GdzdDJkxfciXKcsYr9IIuk\nfaoXgjKR7p1zERiWZuFF63SB4aiyX1H7IX0MwHDZQO38a5gZaOm/BUlGKMWXzuEd\n3fy+1rCUwzOp9LSjtJYf4ege\n-----END PRIVATE KEY-----",
       "certificate" : "-----BEGIN CERTIFICATE-----\nMIIC4TCCAcmgAwIBAgICEREwDQYJKoZIhvcNAQELBQAwFzEVMBMGA1UEAxMMTXlD\nb21wYW55IENBMB4XDTE4MDcwMjEzMjU0N1oXDTQ1MTExNzEzMjU0N1owFDESMBAG\nA1UEAwwJbG9jYWxob3N0MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA\n0FQGzi3ucTX+DNud1p/b4XVM6I3rY7+Cfge5GMLDIUXIHXCfCgp19Z3807yNpLF5\nU0NqPQZKUrZz3rQeLN9mYiUTJZPutYlFDDbB8CtlgV+eyU9yYJslWx/Bm5kWNPh9\n7B9Yu9pbp2u6zDA99IC4ekKD93KuzxlnLmSle4Y3dbYwk0LpMDL6lfCHKt/W7jaS\nIAzlsxD+QM6l7QjhWJ+kUx+UkboOISjTe7E9XmDLJR7u8LRAQylYKy4zgnv1tn/K\ny09cxLKAFtgoZWQD2FAZJf9F7k1kYNwqITz3CPlLZUUn7yw3nkOOtLMI28IEv0Wy\nYd7CMJQkS1NPJBKNOGfR/wIDAQABozowODAhBgNVHREEGjAYggpkb21haW4uY29t\nhwQKuUvJhwR/AAABMBMGA1UdJQQMMAoGCCsGAQUFBwMBMA0GCSqGSIb3DQEBCwUA\nA4IBAQA8lMQJxaTey7EjXtRLSVlEAMftAQPG6jijNQuvIBQYUDauDT4W2XUZ5wAn\njiOyQ83va672K1G9s8n6xlH+xwwdSNnozaKzC87vwSeZKIOdl9I5I98TGKI6OoDa\nezmzCwQYtHBMVQ4c7Ml8554Ft1mWSt4dMAK2rzNYjvPRLYlzp1HMnI6hkjPk4PCZ\nwKnha0dlScati9CCt3UzXSNJOSLalKdHErH08Iqd+1BchScxCfk0xNITn1HZZGmI\n+vbmunok3A2lucI14rnsrcbkGYqxGikySN6B2cRLBDK4Y3wChiW6NVYtVqcx5/mZ\niYsGDVN+9QBd0eYUHce+77s96i3I\n-----END CERTIFICATE-----",
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
       "private_key" : "-----BEGIN PRIVATE KEY-----\nMIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQDQVAbOLe5xNf4M\n253Wn9vhdUzojetjv4J+B7kYwsMhRcgdcJ8KCnX1nfzTvI2ksXlTQ2o9BkpStnPe\ntB4s32ZiJRMlk+61iUUMNsHwK2WBX57JT3JgmyVbH8GbmRY0+H3sH1i72luna7rM\nMD30gLh6QoP3cq7PGWcuZKV7hjd1tjCTQukwMvqV8Icq39buNpIgDOWzEP5AzqXt\nCOFYn6RTH5SRug4hKNN7sT1eYMslHu7wtEBDKVgrLjOCe/W2f8rLT1zEsoAW2Chl\nZAPYUBkl/0XuTWRg3CohPPcI+UtlRSfvLDeeQ460swjbwgS/RbJh3sIwlCRLU08k\nEo04Z9H/AgMBAAECggEAEIeaQqHCWZk/HyYN0Am/GJSGFa2tD60SXY2fUieh8/Hl\nfvCArftGgMaYWPSNCJRMXB7tPwpQu19esjz4Z/cR2Je4fTLPrffGUsHFgZjv5OQB\nZVe4a5Hj1OcgJYhwCqPs2d9i2wToYNBbcfgh8lSETq8YaXngBO6vES9LMhHkNKKr\nciu9YkInNEHu6uRJ5g/eGGX3KQynTvVIhnOVGAJvjTXcoU6fm7gYdHAD6jk9lc9M\nEGpfYI6AdHIwFZcT/RNAxhP82lg2gUJSgAu66FfDjMwQXKbafKdP3zq4Up8a7Ale\nkrguPtfV1vWklg+bUFhgGaiAEYTpAUN9t2DVIiijgQKBgQDnYMMsaF0r557CM1CT\nXUqgCZo8MKeV2jf2drlxRRwRl33SksQbzAQ/qrLdT7GP3sCGqvkxWY2FPdFYf8kx\nGcCeZPcIeZYCQAM41pjtsaM8tVbLWVR8UtGBuQoPSph7JNF3Tm/JH/fbwjpjP7dt\nJ7n8EzkRUNE6aIMHOFEeych/PQKBgQDmf1bMogx63rTcwQ0PEZ9Vt7mTgKYK4aLr\niWgTWHXPZxUQaYhpjXo6+lMI6DpExiDgBAkMzJGIvS7yQiYWU+wthAr9urbWYdGZ\nlS6VjoTkF6r7VZoILXX0fbuXh6lm8K8IQRfBpJff56p9phMwaBpDNDrfpHB5utBU\nxs40yIdp6wKBgQC69Cp/xUwTX7GdxQzEJctYiKnBHKcspAg38zJf3bGSXU/jR4eB\n1lVQhELGI9CbKSdzKM71GyEImix/T7FnJSHIWlho1qVo6AQyduNWnAQD15pr8KAd\nXGXAZZ1FQcb3KYa+2fflERmazdOTwjYZ0tGqZnXkEeMdSLkmqlCRigWhGQKBgDak\n/735uP20KKqhNehZpC2dJei7OiIgRhCS/dKASUXHSW4fptBnUxACYocdDxtY4Vha\nfI7FPMdvGl8ioYbvlHFh+X0Xs9r1S8yeWnHoXMb6eXWmYKMJrAoveLa+2cFm1Agf\n7nLhA4R4lqm9IpV6SKegDUkR4fxp9pPyodZPqBLLAoGBAJkD4wHW54Pwd4Ctfk9o\njHjWB7pQlUYpTZO9dm+4fpCMn9Okf43AE2yAOaAP94GdzdDJkxfciXKcsYr9IIuk\nfaoXgjKR7p1zERiWZuFF63SB4aiyX1H7IX0MwHDZQO38a5gZaOm/BUlGKMWXzuEd\n3fy+1rCUwzOp9LSjtJYf4ege\n-----END PRIVATE KEY-----",
       "certificate" : "-----BEGIN CERTIFICATE-----\nMIIC4TCCAcmgAwIBAgICEREwDQYJKoZIhvcNAQELBQAwFzEVMBMGA1UEAxMMTXlD\nb21wYW55IENBMB4XDTE4MDcwMjEzMjU0N1oXDTQ1MTExNzEzMjU0N1owFDESMBAG\nA1UEAwwJbG9jYWxob3N0MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA\n0FQGzi3ucTX+DNud1p/b4XVM6I3rY7+Cfge5GMLDIUXIHXCfCgp19Z3807yNpLF5\nU0NqPQZKUrZz3rQeLN9mYiUTJZPutYlFDDbB8CtlgV+eyU9yYJslWx/Bm5kWNPh9\n7B9Yu9pbp2u6zDA99IC4ekKD93KuzxlnLmSle4Y3dbYwk0LpMDL6lfCHKt/W7jaS\nIAzlsxD+QM6l7QjhWJ+kUx+UkboOISjTe7E9XmDLJR7u8LRAQylYKy4zgnv1tn/K\ny09cxLKAFtgoZWQD2FAZJf9F7k1kYNwqITz3CPlLZUUn7yw3nkOOtLMI28IEv0Wy\nYd7CMJQkS1NPJBKNOGfR/wIDAQABozowODAhBgNVHREEGjAYggpkb21haW4uY29t\nhwQKuUvJhwR/AAABMBMGA1UdJQQMMAoGCCsGAQUFBwMBMA0GCSqGSIb3DQEBCwUA\nA4IBAQA8lMQJxaTey7EjXtRLSVlEAMftAQPG6jijNQuvIBQYUDauDT4W2XUZ5wAn\njiOyQ83va672K1G9s8n6xlH+xwwdSNnozaKzC87vwSeZKIOdl9I5I98TGKI6OoDa\nezmzCwQYtHBMVQ4c7Ml8554Ft1mWSt4dMAK2rzNYjvPRLYlzp1HMnI6hkjPk4PCZ\nwKnha0dlScati9CCt3UzXSNJOSLalKdHErH08Iqd+1BchScxCfk0xNITn1HZZGmI\n+vbmunok3A2lucI14rnsrcbkGYqxGikySN6B2cRLBDK4Y3wChiW6NVYtVqcx5/mZ\niYsGDVN+9QBd0eYUHce+77s96i3I\n-----END CERTIFICATE-----",
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
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
200         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Viewing Details of a Certificate
================================

Function
^^^^^^^^

This API is used to view details of an SSL certificate.

URI
^^^

GET /v3/{project_id}/elb/certificates/{certificate_id}

.. table:: **Table 1** Path parameters

   ============== ========= ====== ===========================
   Parameter      Mandatory Type   Description
   ============== ========= ====== ===========================
   project_id     Yes       String Specifies the project ID.
   certificate_id Yes       String Specifies a certificate ID.
   ============== ========= ====== ===========================

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 200**

.. table:: **Table 3** Response body parameters

   +-------------+--------------------------------------------------+----------------------------------------+
   | Parameter   | Type                                             | Description                            |
   +=============+==================================================+========================================+
   | request_id  | String                                           | Specifies the request ID. The value is |
   |             |                                                  | automatically generated.               |
   +-------------+--------------------------------------------------+----------------------------------------+
   | certificate | :ref:`dcs_ci` object                             | Specifies the certificate.             |
   +-------------+--------------------------------------------------+----------------------------------------+

.. _dcs_ci:
.. table:: **Table 4** CertificateInfo

   +----------------+---------+---------------------------------------+
   | Parameter      | Type    | Description                           |
   +================+=========+=======================================+
   | admin_state_up | Boolean | Specifies the administrative status   |
   |                |         | of the certificate.                   |
   |                |         |                                       |
   |                |         | This parameter is unsupported. Please |
   |                |         | do not use it.                        |
   +----------------+---------+---------------------------------------+
   | certificate    | String  | Specifies the private key of the      |
   |                |         | certificate. The value must be PEM    |
   |                |         | encoded.                              |
   +----------------+---------+---------------------------------------+
   | description    | String  | Provides supplementary information    |
   |                |         | about the certificate.                |
   |                |         |                                       |
   |                |         | Minimum: **1**                        |
   |                |         |                                       |
   |                |         | Maximum: **255**                      |
   +----------------+---------+---------------------------------------+
   | domain         | String  | Specifies the domain names used by    |
   |                |         | the server certificate.               |
   |                |         |                                       |
   |                |         | -  This parameter will take effect    |
   |                |         |    only when **type** is set to       |
   |                |         |    **server**, and its default value  |
   |                |         |    is **""**.                         |
   |                |         |                                       |
   |                |         | -  This parameter will not take       |
   |                |         |    effect even if it is passed and    |
   |                |         |    **type** is set to **client**.     |
   |                |         |    However, domain names will still   |
   |                |         |    be verified.                       |
   |                |         |                                       |
   |                |         | Note:                                 |
   |                |         |                                       |
   |                |         | -  The value can contain 0 to 1024    |
   |                |         |    characters and consists of         |
   |                |         |    multiple common domain names or    |
   |                |         |    wildcard domain names separated by |
   |                |         |    commas. A maximum of 30 domain     |
   |                |         |    names are allowed.                 |
   |                |         |                                       |
   |                |         | -  A common domain name consists of   |
   |                |         |    several labels separated by        |
   |                |         |    periods (.). Each label can        |
   |                |         |    contain a maximum of 63            |
   |                |         |    characters, including letters,     |
   |                |         |    digits, and hyphens (-), and must  |
   |                |         |    start and end with a letter or     |
   |                |         |    digit. Example: www.test.com       |
   |                |         |                                       |
   |                |         | -  A wildcard domain name is a domain |
   |                |         |    name starts with an asterisk (*).  |
   |                |         |    Example: \*.test.com               |
   |                |         |                                       |
   |                |         | Minimum: **1**                        |
   |                |         |                                       |
   |                |         | Maximum: **1024**                     |
   +----------------+---------+---------------------------------------+
   | id             | String  | Specifies a certificate ID.           |
   +----------------+---------+---------------------------------------+
   | name           | String  | Specifies the certificate name.       |
   |                |         |                                       |
   |                |         | Minimum: **1**                        |
   |                |         |                                       |
   |                |         | Maximum: **255**                      |
   +----------------+---------+---------------------------------------+
   | private_key    | String  | Specifies the private key of the      |
   |                |         | server certificate. The value must be |
   |                |         | PEM encoded.                          |
   |                |         |                                       |
   |                |         | -  This parameter will be ignored if  |
   |                |         |    **type** is set to **client**. A   |
   |                |         |    CA server can still be created and |
   |                |         |    used normally. This parameter will |
   |                |         |    be left blank even if you enter a  |
   |                |         |    private key that is not PEM        |
   |                |         |    encoded.                           |
   |                |         |                                       |
   |                |         | -  This parameter is valid and        |
   |                |         |    mandatory only when **type** is    |
   |                |         |    set to **server**. If you enter an |
   |                |         |    invalid private key, an error is   |
   |                |         |    returned.                          |
   +----------------+---------+---------------------------------------+
   | type           | String  | Specifies the certificate type. The   |
   |                |         | value can be **server** or            |
   |                |         | **client**. **server** indicates      |
   |                |         | server certificates, and **client**   |
   |                |         | indicates CA certificates. The        |
   |                |         | default value is **server**.          |
   +----------------+---------+---------------------------------------+
   | created_at     | String  | Specifies the time when the           |
   |                |         | certificate was created.              |
   +----------------+---------+---------------------------------------+
   | updated_at     | String  | Specifies the time when the           |
   |                |         | certificate was updated.              |
   +----------------+---------+---------------------------------------+
   | expire_time    | String  | Specifies the time when the           |
   |                |         | certificate expires.                  |
   +----------------+---------+---------------------------------------+
   | project_id     | String  | Specifies the project ID.             |
   +----------------+---------+---------------------------------------+

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   GET
   https://{elb_endpoint}/v3/{project_id}/elb/certificates/{certificate_id}

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

   {
     "certificate" : {
       "id" : "5494a835d88f40ff940554992f2f04d4",
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "name" : "https_certificatekkkk",
       "type" : "server",
       "description" : "description for certificatehhhh",
       "private_key" : "-----BEGIN PRIVATE KEY-----\nMIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQDQVAbOLe5xNf4M\n253Wn9vhdUzojetjv4J+B7kYwsMhRcgdcJ8KCnX1nfzTvI2ksXlTQ2o9BkpStnPe\ntB4s32ZiJRMlk+61iUUMNsHwK2WBX57JT3JgmyVbH8GbmRY0+H3sH1i72luna7rM\nMD30gLh6QoP3cq7PGWcuZKV7hjd1tjCTQukwMvqV8Icq39buNpIgDOWzEP5AzqXt\nCOFYn6RTH5SRug4hKNN7sT1eYMslHu7wtEBDKVgrLjOCe/W2f8rLT1zEsoAW2Chl\nZAPYUBkl/0XuTWRg3CohPPcI+UtlRSfvLDeeQ460swjbwgS/RbJh3sIwlCRLU08k\nEo04Z9H/AgMBAAECggEAEIeaQqHCWZk/HyYN0Am/GJSGFa2tD60SXY2fUieh8/Hl\nfvCArftGgMaYWPSNCJRMXB7tPwpQu19esjz4Z/cR2Je4fTLPrffGUsHFgZjv5OQB\nZVe4a5Hj1OcgJYhwCqPs2d9i2wToYNBbcfgh8lSETq8YaXngBO6vES9LMhHkNKKr\nciu9YkInNEHu6uRJ5g/eGGX3KQynTvVIhnOVGAJvjTXcoU6fm7gYdHAD6jk9lc9M\nEGpfYI6AdHIwFZcT/RNAxhP82lg2gUJSgAu66FfDjMwQXKbafKdP3zq4Up8a7Ale\nkrguPtfV1vWklg+bUFhgGaiAEYTpAUN9t2DVIiijgQKBgQDnYMMsaF0r557CM1CT\nXUqgCZo8MKeV2jf2drlxRRwRl33SksQbzAQ/qrLdT7GP3sCGqvkxWY2FPdFYf8kx\nGcCeZPcIeZYCQAM41pjtsaM8tVbLWVR8UtGBuQoPSph7JNF3Tm/JH/fbwjpjP7dt\nJ7n8EzkRUNE6aIMHOFEeych/PQKBgQDmf1bMogx63rTcwQ0PEZ9Vt7mTgKYK4aLr\niWgTWHXPZxUQaYhpjXo6+lMI6DpExiDgBAkMzJGIvS7yQiYWU+wthAr9urbWYdGZ\nlS6VjoTkF6r7VZoILXX0fbuXh6lm8K8IQRfBpJff56p9phMwaBpDNDrfpHB5utBU\nxs40yIdp6wKBgQC69Cp/xUwTX7GdxQzEJctYiKnBHKcspAg38zJf3bGSXU/jR4eB\n1lVQhELGI9CbKSdzKM71GyEImix/T7FnJSHIWlho1qVo6AQyduNWnAQD15pr8KAd\nXGXAZZ1FQcb3KYa+2fflERmazdOTwjYZ0tGqZnXkEeMdSLkmqlCRigWhGQKBgDak\n/735uP20KKqhNehZpC2dJei7OiIgRhCS/dKASUXHSW4fptBnUxACYocdDxtY4Vha\nfI7FPMdvGl8ioYbvlHFh+X0Xs9r1S8yeWnHoXMb6eXWmYKMJrAoveLa+2cFm1Agf\n7nLhA4R4lqm9IpV6SKegDUkR4fxp9pPyodZPqBLLAoGBAJkD4wHW54Pwd4Ctfk9o\njHjWB7pQlUYpTZO9dm+4fpCMn9Okf43AE2yAOaAP94GdzdDJkxfciXKcsYr9IIuk\nfaoXgjKR7p1zERiWZuFF63SB4aiyX1H7IX0MwHDZQO38a5gZaOm/BUlGKMWXzuEd\n3fy+1rCUwzOp9LSjtJYf4ege\n-----END PRIVATE KEY-----",
       "certificate" : "-----BEGIN CERTIFICATE-----\nMIIC4TCCAcmgAwIBAgICEREwDQYJKoZIhvcNAQELBQAwFzEVMBMGA1UEAxMMTXlD\nb21wYW55IENBMB4XDTE4MDcwMjEzMjU0N1oXDTQ1MTExNzEzMjU0N1owFDESMBAG\nA1UEAwwJbG9jYWxob3N0MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA\n0FQGzi3ucTX+DNud1p/b4XVM6I3rY7+Cfge5GMLDIUXIHXCfCgp19Z3807yNpLF5\nU0NqPQZKUrZz3rQeLN9mYiUTJZPutYlFDDbB8CtlgV+eyU9yYJslWx/Bm5kWNPh9\n7B9Yu9pbp2u6zDA99IC4ekKD93KuzxlnLmSle4Y3dbYwk0LpMDL6lfCHKt/W7jaS\nIAzlsxD+QM6l7QjhWJ+kUx+UkboOISjTe7E9XmDLJR7u8LRAQylYKy4zgnv1tn/K\ny09cxLKAFtgoZWQD2FAZJf9F7k1kYNwqITz3CPlLZUUn7yw3nkOOtLMI28IEv0Wy\nYd7CMJQkS1NPJBKNOGfR/wIDAQABozowODAhBgNVHREEGjAYggpkb21haW4uY29t\nhwQKuUvJhwR/AAABMBMGA1UdJQQMMAoGCCsGAQUFBwMBMA0GCSqGSIb3DQEBCwUA\nA4IBAQA8lMQJxaTey7EjXtRLSVlEAMftAQPG6jijNQuvIBQYUDauDT4W2XUZ5wAn\njiOyQ83va672K1G9s8n6xlH+xwwdSNnozaKzC87vwSeZKIOdl9I5I98TGKI6OoDa\nezmzCwQYtHBMVQ4c7Ml8554Ft1mWSt4dMAK2rzNYjvPRLYlzp1HMnI6hkjPk4PCZ\nwKnha0dlScati9CCt3UzXSNJOSLalKdHErH08Iqd+1BchScxCfk0xNITn1HZZGmI\n+vbmunok3A2lucI14rnsrcbkGYqxGikySN6B2cRLBDK4Y3wChiW6NVYtVqcx5/mZ\niYsGDVN+9QBd0eYUHce+77s96i3I\n-----END CERTIFICATE-----",
       "admin_state_up" : true,
       "created_at" : "2019-03-31T22:23:51Z",
       "updated_at" : "2019-03-31T23:26:49Z",
       "expire_time" : "2045-11-17T13:25:47Z"
     },
     "request_id" : "a94af450-5ac0-4185-946c-27a59a16c1d3"
   }

Status Codes
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
200         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Updating a Certificate
======================

Function
^^^^^^^^

This API is used to update an SSL certificate.

URI
^^^

PUT /v3/{project_id}/elb/certificates/{certificate_id}

.. table:: **Table 1** Path parameters

   ============== ========= ====== ============================================
   Parameter      Mandatory Type   Description
   ============== ========= ====== ============================================
   certificate_id Yes       String Specifies a certificate ID.
   project_id     Yes       String Specifies the project ID of the certificate.
   ============== ========= ====== ============================================

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

.. table:: **Table 3** Request body parameters

   +-------------+-----------+---------------------+-------------------------------------------+
   | Parameter   | Mandatory | Type                | Description                               |
   +=============+===========+=====================+===========================================+
   | certificate | Yes       | :ref:`dcu_o` object | Specifies request parameters for updating |
   |             |           |                     | a certificate.                            |
   +-------------+-----------+---------------------+-------------------------------------------+

.. _dcu_o:
.. table:: **Table 4** UpdateCertificateOption

   +-------------+-----------+--------+-----------------------------+
   | Parameter   | Mandatory | Type   | Description                 |
   +=============+===========+========+=============================+
   | certificate | No        | String | Specifies the private key   |
   |             |           |        | of the certificate. The     |
   |             |           |        | value must be PEM encoded.  |
   +-------------+-----------+--------+-----------------------------+
   | description | No        | String | Provides supplementary      |
   |             |           |        | information about the       |
   |             |           |        | certificate.                |
   |             |           |        |                             |
   |             |           |        | Minimum: **0**              |
   |             |           |        |                             |
   |             |           |        | Maximum: **255**            |
   +-------------+-----------+--------+-----------------------------+
   | name        | No        | String | Specifies the certificate   |
   |             |           |        | name.                       |
   |             |           |        |                             |
   |             |           |        | Minimum: **0**              |
   |             |           |        |                             |
   |             |           |        | Maximum: **255**            |
   +-------------+-----------+--------+-----------------------------+
   | private_key | No        | String | Specifies the private key   |
   |             |           |        | of the server certificate.  |
   |             |           |        | The value must be PEM       |
   |             |           |        | encoded.                    |
   |             |           |        |                             |
   |             |           |        | -  This parameter will be   |
   |             |           |        |    ignored if **type** is   |
   |             |           |        |    set to **client**. A CA  |
   |             |           |        |    server can still be      |
   |             |           |        |    created and used         |
   |             |           |        |    normally. This parameter |
   |             |           |        |    will be left blank even  |
   |             |           |        |    if you enter a private   |
   |             |           |        |    key that is not PEM      |
   |             |           |        |    encoded.                 |
   |             |           |        |                             |
   |             |           |        | -  This parameter is valid  |
   |             |           |        |    and mandatory only when  |
   |             |           |        |    **type** is set to       |
   |             |           |        |    **server**. If you enter |
   |             |           |        |    an invalid private key,  |
   |             |           |        |    an error is returned.    |
   +-------------+-----------+--------+-----------------------------+
   | domain      | No        | String | Specifies the domain names  |
   |             |           |        | used by the server          |
   |             |           |        | certificate.                |
   |             |           |        |                             |
   |             |           |        | -  This parameter will take |
   |             |           |        |    effect only when         |
   |             |           |        |    **type** is set to       |
   |             |           |        |    **server**, and its      |
   |             |           |        |    default value is **""**. |
   |             |           |        |                             |
   |             |           |        | -  This parameter will not  |
   |             |           |        |    take effect even if it   |
   |             |           |        |    is passed and **type**   |
   |             |           |        |    is set to **client**.    |
   |             |           |        |    However, domain names    |
   |             |           |        |    will still be verified.  |
   |             |           |        |                             |
   |             |           |        | Note:                       |
   |             |           |        |                             |
   |             |           |        | -  The value can contain 0  |
   |             |           |        |    to 1024 characters and   |
   |             |           |        |    consists of multiple     |
   |             |           |        |    common domain names or   |
   |             |           |        |    wildcard domain names    |
   |             |           |        |    separated by commas. A   |
   |             |           |        |    maximum of 30 domain     |
   |             |           |        |    names are allowed.       |
   |             |           |        |                             |
   |             |           |        | -  A common domain name     |
   |             |           |        |    consists of several      |
   |             |           |        |    labels separated by      |
   |             |           |        |    periods (.). Each label  |
   |             |           |        |    can contain a maximum of |
   |             |           |        |    63 characters, including |
   |             |           |        |    letters, digits, and     |
   |             |           |        |    hyphens (-), and must    |
   |             |           |        |    start and end with a     |
   |             |           |        |    letter or digit.         |
   |             |           |        |    Example: www.test.com    |
   |             |           |        |                             |
   |             |           |        | -  A wildcard domain name   |
   |             |           |        |    is a domain name starts  |
   |             |           |        |    with an asterisk (*).    |
   |             |           |        |    Example: \*.test.com     |
   |             |           |        |                             |
   |             |           |        | Minimum: **0**              |
   |             |           |        |                             |
   |             |           |        | Maximum: **1024**           |
   +-------------+-----------+--------+-----------------------------+

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 200**

.. table:: **Table 5** Response body parameters

   +-------------+----------------------+----------------------------------------+
   | Parameter   | Type                 | Description                            |
   +=============+======================+========================================+
   | request_id  | String               | Specifies the request ID. The value is |
   |             |                      | automatically generated.               |
   +-------------+----------------------+----------------------------------------+
   | certificate | :ref:`dcu_ci` object | Specifies the certificate.             |
   +-------------+----------------------+----------------------------------------+

.. _dcu_ci:
.. table:: **Table 6** CertificateInfo

   +----------------+---------+---------------------------------------+
   | Parameter      | Type    | Description                           |
   +================+=========+=======================================+
   | admin_state_up | Boolean | Specifies the administrative status   |
   |                |         | of the certificate.                   |
   |                |         |                                       |
   |                |         | This parameter is unsupported. Please |
   |                |         | do not use it.                        |
   +----------------+---------+---------------------------------------+
   | certificate    | String  | Specifies the private key of the      |
   |                |         | certificate. The value must be PEM    |
   |                |         | encoded.                              |
   +----------------+---------+---------------------------------------+
   | description    | String  | Provides supplementary information    |
   |                |         | about the certificate.                |
   |                |         |                                       |
   |                |         | Minimum: **1**                        |
   |                |         |                                       |
   |                |         | Maximum: **255**                      |
   +----------------+---------+---------------------------------------+
   | domain         | String  | Specifies the domain names used by    |
   |                |         | the server certificate.               |
   |                |         |                                       |
   |                |         | -  This parameter will take effect    |
   |                |         |    only when **type** is set to       |
   |                |         |    **server**, and its default value  |
   |                |         |    is **""**.                         |
   |                |         |                                       |
   |                |         | -  This parameter will not take       |
   |                |         |    effect even if it is passed and    |
   |                |         |    **type** is set to **client**.     |
   |                |         |    However, domain names will still   |
   |                |         |    be verified.                       |
   |                |         |                                       |
   |                |         | Note:                                 |
   |                |         |                                       |
   |                |         | -  The value can contain 0 to 1024    |
   |                |         |    characters and consists of         |
   |                |         |    multiple common domain names or    |
   |                |         |    wildcard domain names separated by |
   |                |         |    commas. A maximum of 30 domain     |
   |                |         |    names are allowed.                 |
   |                |         |                                       |
   |                |         | -  A common domain name consists of   |
   |                |         |    several labels separated by        |
   |                |         |    periods (.). Each label can        |
   |                |         |    contain a maximum of 63            |
   |                |         |    characters, including letters,     |
   |                |         |    digits, and hyphens (-), and must  |
   |                |         |    start and end with a letter or     |
   |                |         |    digit. Example: www.test.com       |
   |                |         |                                       |
   |                |         | -  A wildcard domain name is a domain |
   |                |         |    name starts with an asterisk (*).  |
   |                |         |    Example: \*.test.com               |
   |                |         |                                       |
   |                |         | Minimum: **1**                        |
   |                |         |                                       |
   |                |         | Maximum: **1024**                     |
   +----------------+---------+---------------------------------------+
   | id             | String  | Specifies a certificate ID.           |
   +----------------+---------+---------------------------------------+
   | name           | String  | Specifies the certificate name.       |
   |                |         |                                       |
   |                |         | Minimum: **1**                        |
   |                |         |                                       |
   |                |         | Maximum: **255**                      |
   +----------------+---------+---------------------------------------+
   | private_key    | String  | Specifies the private key of the      |
   |                |         | server certificate. The value must be |
   |                |         | PEM encoded.                          |
   |                |         |                                       |
   |                |         | -  This parameter will be ignored if  |
   |                |         |    **type** is set to **client**. A   |
   |                |         |    CA server can still be created and |
   |                |         |    used normally. This parameter will |
   |                |         |    be left blank even if you enter a  |
   |                |         |    private key that is not PEM        |
   |                |         |    encoded.                           |
   |                |         |                                       |
   |                |         | -  This parameter is valid and        |
   |                |         |    mandatory only when **type** is    |
   |                |         |    set to **server**. If you enter an |
   |                |         |    invalid private key, an error is   |
   |                |         |    returned.                          |
   +----------------+---------+---------------------------------------+
   | type           | String  | Specifies the certificate type. The   |
   |                |         | value can be **server** or            |
   |                |         | **client**. **server** indicates      |
   |                |         | server certificates, and **client**   |
   |                |         | indicates CA certificates. The        |
   |                |         | default value is **server**.          |
   +----------------+---------+---------------------------------------+
   | created_at     | String  | Specifies the time when the           |
   |                |         | certificate was created.              |
   +----------------+---------+---------------------------------------+
   | updated_at     | String  | Specifies the time when the           |
   |                |         | certificate was updated.              |
   +----------------+---------+---------------------------------------+
   | expire_time    | String  | Specifies the time when the           |
   |                |         | certificate expires.                  |
   +----------------+---------+---------------------------------------+
   | project_id     | String  | Specifies the project ID.             |
   +----------------+---------+---------------------------------------+

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   PUT
   https://{elb_endponit}/v3/{project_id}/elb/certificates/{certificate_id}

   {
     "certificate" : {
       "name" : "My Certificate",
       "description" : "Update my Certificate."
     }
   }

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

   {
     "certificate" : {
       "private_key" : "-----BEGIN PRIVATE KEY-----\nMIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQDQVAbOLe5xNf4M\n253Wn9vhdUzojetjv4J+B7kYwsMhRcgdcJ8KCnX1nfzTvI2ksXlTQ2o9BkpStnPe\ntB4s32ZiJRMlk+61iUUMNsHwK2WBX57JT3JgmyVbH8GbmRY0+H3sH1i72luna7rM\nMD30gLh6QoP3cq7PGWcuZKV7hjd1tjCTQukwMvqV8Icq39buNpIgDOWzEP5AzqXt\nCOFYn6RTH5SRug4hKNN7sT1eYMslHu7wtEBDKVgrLjOCe/W2f8rLT1zEsoAW2Chl\nZAPYUBkl/0XuTWRg3CohPPcI+UtlRSfvLDeeQ460swjbwgS/RbJh3sIwlCRLU08k\nEo04Z9H/AgMBAAECggEAEIeaQqHCWZk/HyYN0Am/GJSGFa2tD60SXY2fUieh8/Hl\nfvCArftGgMaYWPSNCJRMXB7tPwpQu19esjz4Z/cR2Je4fTLPrffGUsHFgZjv5OQB\nZVe4a5Hj1OcgJYhwCqPs2d9i2wToYNBbcfgh8lSETq8YaXngBO6vES9LMhHkNKKr\nciu9YkInNEHu6uRJ5g/eGGX3KQynTvVIhnOVGAJvjTXcoU6fm7gYdHAD6jk9lc9M\nEGpfYI6AdHIwFZcT/RNAxhP82lg2gUJSgAu66FfDjMwQXKbafKdP3zq4Up8a7Ale\nkrguPtfV1vWklg+bUFhgGaiAEYTpAUN9t2DVIiijgQKBgQDnYMMsaF0r557CM1CT\nXUqgCZo8MKeV2jf2drlxRRwRl33SksQbzAQ/qrLdT7GP3sCGqvkxWY2FPdFYf8kx\nGcCeZPcIeZYCQAM41pjtsaM8tVbLWVR8UtGBuQoPSph7JNF3Tm/JH/fbwjpjP7dt\nJ7n8EzkRUNE6aIMHOFEeych/PQKBgQDmf1bMogx63rTcwQ0PEZ9Vt7mTgKYK4aLr\niWgTWHXPZxUQaYhpjXo6+lMI6DpExiDgBAkMzJGIvS7yQiYWU+wthAr9urbWYdGZ\nlS6VjoTkF6r7VZoILXX0fbuXh6lm8K8IQRfBpJff56p9phMwaBpDNDrfpHB5utBU\nxs40yIdp6wKBgQC69Cp/xUwTX7GdxQzEJctYiKnBHKcspAg38zJf3bGSXU/jR4eB\n1lVQhELGI9CbKSdzKM71GyEImix/T7FnJSHIWlho1qVo6AQyduNWnAQD15pr8KAd\nXGXAZZ1FQcb3KYa+2fflERmazdOTwjYZ0tGqZnXkEeMdSLkmqlCRigWhGQKBgDak\n/735uP20KKqhNehZpC2dJei7OiIgRhCS/dKASUXHSW4fptBnUxACYocdDxtY4Vha\nfI7FPMdvGl8ioYbvlHFh+X0Xs9r1S8yeWnHoXMb6eXWmYKMJrAoveLa+2cFm1Agf\n7nLhA4R4lqm9IpV6SKegDUkR4fxp9pPyodZPqBLLAoGBAJkD4wHW54Pwd4Ctfk9o\njHjWB7pQlUYpTZO9dm+4fpCMn9Okf43AE2yAOaAP94GdzdDJkxfciXKcsYr9IIuk\nfaoXgjKR7p1zERiWZuFF63SB4aiyX1H7IX0MwHDZQO38a5gZaOm/BUlGKMWXzuEd\n3fy+1rCUwzOp9LSjtJYf4ege\n-----END PRIVATE KEY-----",
       "description" : "Update my Certificate.",
       "created_at" : "2019-03-31T22:23:51Z",
       "expire_time" : "2045-11-17T13:25:47Z",
       "id" : "233a325e5e3e4ce8beeb320aa714cc12",
       "name" : "My Certificate",
       "certificate" : "-----BEGIN CERTIFICATE-----\nMIIC4TCCAcmgAwIBAgICEREwDQYJKoZIhvcNAQELBQAwFzEVMBMGA1UEAxMMTXlD\nb21wYW55IENBMB4XDTE4MDcwMjEzMjU0N1oXDTQ1MTExNzEzMjU0N1owFDESMBAG\nA1UEAwwJbG9jYWxob3N0MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA\n0FQGzi3ucTX+DNud1p/b4XVM6I3rY7+Cfge5GMLDIUXIHXCfCgp19Z3807yNpLF5\nU0NqPQZKUrZz3rQeLN9mYiUTJZPutYlFDDbB8CtlgV+eyU9yYJslWx/Bm5kWNPh9\n7B9Yu9pbp2u6zDA99IC4ekKD93KuzxlnLmSle4Y3dbYwk0LpMDL6lfCHKt/W7jaS\nIAzlsxD+QM6l7QjhWJ+kUx+UkboOISjTe7E9XmDLJR7u8LRAQylYKy4zgnv1tn/K\ny09cxLKAFtgoZWQD2FAZJf9F7k1kYNwqITz3CPlLZUUn7yw3nkOOtLMI28IEv0Wy\nYd7CMJQkS1NPJBKNOGfR/wIDAQABozowODAhBgNVHREEGjAYggpkb21haW4uY29t\nhwQKuUvJhwR/AAABMBMGA1UdJQQMMAoGCCsGAQUFBwMBMA0GCSqGSIb3DQEBCwUA\nA4IBAQA8lMQJxaTey7EjXtRLSVlEAMftAQPG6jijNQuvIBQYUDauDT4W2XUZ5wAn\njiOyQ83va672K1G9s8n6xlH+xwwdSNnozaKzC87vwSeZKIOdl9I5I98TGKI6OoDa\nezmzCwQYtHBMVQ4c7Ml8554Ft1mWSt4dMAK2rzNYjvPRLYlzp1HMnI6hkjPk4PCZ\nwKnha0dlScati9CCt3UzXSNJOSLalKdHErH08Iqd+1BchScxCfk0xNITn1HZZGmI\n+vbmunok3A2lucI14rnsrcbkGYqxGikySN6B2cRLBDK4Y3wChiW6NVYtVqcx5/mZ\niYsGDVN+9QBd0eYUHce+77s96i3I\n-----END CERTIFICATE-----",
       "admin_state_up" : true,
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24",
       "updated_at" : "2019-03-31T23:26:49Z",
       "type" : "server"
     },
     "request_id" : "d9abea6b-98ee-4ad4-8c5d-185ded48742f"
   }

Status Codes
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
200         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

Deleting a Certificate
======================

Function
^^^^^^^^

This API is used to delete an SSL certificate.

Constraints
^^^^^^^^^^^

If the certificate is used by a listener, the certificate cannot be deleted,
and the 409 Conflict error code will be displayed.

URI
^^^

DELETE /v3/{project_id}/elb/certificates/{certificate_id}

.. table:: **Table 1** Path parameters

   ============== ========= ====== ===========================
   Parameter      Mandatory Type   Description
   ============== ========= ====== ===========================
   project_id     Yes       String Specifies the project ID.
   certificate_id Yes       String Specifies a certificate ID.
   ============== ========= ====== ===========================

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

Response Parameters
^^^^^^^^^^^^^^^^^^^

None

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   DELETE
   https://{elb_endpoint}/v3/{project_id}/elb/certificates/{certificate_id}

Example Responses
^^^^^^^^^^^^^^^^^

None

Status Codes
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
204         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.
