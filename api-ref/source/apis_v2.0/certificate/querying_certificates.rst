:original_name: elb_zq_zs_0002.html

.. _elb_zq_zs_0002:

Querying Certificates
=====================

Function
--------

This API is used to query all the certificates. Filter query and pagination query are supported. Unless otherwise specified, exact match is applied.

Constraints
-----------

Parameters **marker**, **limit**, and **page_reverse** are used for pagination query. Parameters **marker** and **page_reverse** take effect only when they are used together with parameter **limit**.

URI
---

GET /v2.0/lbaas/certificates

Request
-------

.. table:: **Table 1** Parameter description

   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                                                                                                                                                                                                                                                |
   +=================+=================+=================+============================================================================================================================================================================================================================================================================================================================================+
   | marker          | No              | String          | Specifies the ID of the certificate from which pagination query starts, that is, the ID of the last certificate on the previous page.                                                                                                                                                                                                      |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 | This parameter must be used together with **limit**.                                                                                                                                                                                                                                                                                       |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | limit           | No              | Integer         | Specifies the number of certificates on each page. If this parameter is not set, all certificates are queried by default.                                                                                                                                                                                                                  |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | page_reverse    | No              | Boolean         | Specifies the page direction. The value can be **true** or **false**, and the default value is **false**. The last page in the list requested with **page_reverse** set to **false** will not contain the "next" link, and the last page in the list requested with **page_reverse** set to **true** will not contain the "previous" link. |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 | This parameter must be used together with **limit**.                                                                                                                                                                                                                                                                                       |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | id              | No              | String          | Specifies the certificate ID.                                                                                                                                                                                                                                                                                                              |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name            | No              | String          | Specifies the certificate name.                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 | The value contains a maximum of 255 characters.                                                                                                                                                                                                                                                                                            |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | description     | No              | String          | Provides supplementary information about the certificate.                                                                                                                                                                                                                                                                                  |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 | The value contains a maximum of 255 characters.                                                                                                                                                                                                                                                                                            |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type            | No              | String          | Specifies the certificate type. The default value is **server**.                                                                                                                                                                                                                                                                           |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 | The value can be one of the following:                                                                                                                                                                                                                                                                                                     |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 | -  **server**: indicates the server certificate.                                                                                                                                                                                                                                                                                           |
   |                 |                 |                 | -  **client**: indicates the CA certificate.                                                                                                                                                                                                                                                                                               |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | domain          | No              | String          | Specifies the domain name associated with the server certificate.                                                                                                                                                                                                                                                                          |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 | A domain name can contain up to 10,000 characters. You can specify up to 100 domain names and separate them using commas (,).                                                                                                                                                                                                              |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 | The value can be one of the following:                                                                                                                                                                                                                                                                                                     |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 | -  A common domain name contains 0 to 100 characters and consists of several labels separated by dots (.). Each label can contain a maximum of 63 characters, including letters, digits, and hyphens (-), and must start and end with a letter or digit. Example: www.test.com                                                             |
   |                 |                 |                 | -  In addition to the requirements for common domain names, a wildcard domain name can start with an asterisk (*). Example: \*.test.com                                                                                                                                                                                                    |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 | .. note::                                                                                                                                                                                                                                                                                                                                  |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 |    -  This parameter is valid only when **type** is set to **server**.                                                                                                                                                                                                                                                                     |
   |                 |                 |                 |    -  SNI certificates of a dedicated load balancer's listener can have up to 200 domain names.                                                                                                                                                                                                                                            |
   |                 |                 |                 |    -  SNI certificates of a shared load balancer's listener can have up to 30 domain names.                                                                                                                                                                                                                                                |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | private_key     | No              | String          | Specifies the private key of the server certificate. The value must be PEM encoded.                                                                                                                                                                                                                                                        |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 | -  This parameter will be ignored if **type** is set to **client**. A CA server can still be created and used normally. This parameter will be left blank even if you enter a private key that is not PEM encoded.                                                                                                                         |
   |                 |                 |                 | -  This parameter is valid and mandatory only when **type** is set to **server**. If you enter an invalid private key, an error is returned.                                                                                                                                                                                               |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | certificate     | No              | String          | Specifies the public key of the server certificate or CA certificate used to authenticate the client. The value of parameter **type** determines whether a public key or CA certificate is required. Both types of certificates are in PEM format.                                                                                         |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | create_time     | No              | String          | Specifies the time when the certificate was created.                                                                                                                                                                                                                                                                                       |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 | The UTC time is in *YYYY-MM-DD HH:MM:SS* format.                                                                                                                                                                                                                                                                                           |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | update_time     | No              | String          | Specifies the time when the certificate was updated.                                                                                                                                                                                                                                                                                       |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                            |
   |                 |                 |                 | The UTC time is in *YYYY-MM-DD HH:MM:SS* format.                                                                                                                                                                                                                                                                                           |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Response
--------

.. table:: **Table 2** Parameter description

   +--------------+---------+--------------------------------------------------------------------------------------------------------------------+
   | Parameter    | Type    | Description                                                                                                        |
   +==============+=========+====================================================================================================================+
   | certificates | Array   | Lists the certificates. For details, see :ref:`Table 3 <elb_zq_zs_0002__en-us_topic_0096561582_table10415837566>`. |
   +--------------+---------+--------------------------------------------------------------------------------------------------------------------+
   | instance_num | Integer | Specifies the number of certificates.                                                                              |
   +--------------+---------+--------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_zs_0002__en-us_topic_0096561582_table10415837566:

.. table:: **Table 3** **certificates** parameter description

   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                                                                                                                                                                                                                                    |
   +=======================+=======================+================================================================================================================================================================================================================================================================================+
   | id                    | String                | Specifies the certificate ID.                                                                                                                                                                                                                                                  |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tenant_id             | String                | Specifies the ID of the project where the certificate is used.                                                                                                                                                                                                                 |
   |                       |                       |                                                                                                                                                                                                                                                                                |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                                                                                                                                                |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | admin_state_up        | Boolean               | Specifies the administrative status of the certificate.                                                                                                                                                                                                                        |
   |                       |                       |                                                                                                                                                                                                                                                                                |
   |                       |                       | This parameter is reserved. The value can be **true** or **false**.                                                                                                                                                                                                            |
   |                       |                       |                                                                                                                                                                                                                                                                                |
   |                       |                       | -  **true**: Enabled                                                                                                                                                                                                                                                           |
   |                       |                       | -  **false**: Disabled                                                                                                                                                                                                                                                         |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | name                  | String                | Specifies the certificate name.                                                                                                                                                                                                                                                |
   |                       |                       |                                                                                                                                                                                                                                                                                |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                                                                                                                                                |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | description           | String                | Provides supplementary information about the certificate.                                                                                                                                                                                                                      |
   |                       |                       |                                                                                                                                                                                                                                                                                |
   |                       |                       | The value contains a maximum of 255 characters.                                                                                                                                                                                                                                |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | type                  | String                | Specifies the certificate type.                                                                                                                                                                                                                                                |
   |                       |                       |                                                                                                                                                                                                                                                                                |
   |                       |                       | The value can be one of the following:                                                                                                                                                                                                                                         |
   |                       |                       |                                                                                                                                                                                                                                                                                |
   |                       |                       | -  **server**: indicates the server certificate.                                                                                                                                                                                                                               |
   |                       |                       | -  **client**: indicates the CA certificate.                                                                                                                                                                                                                                   |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | domain                | String                | Specifies the domain name associated with the server certificate.                                                                                                                                                                                                              |
   |                       |                       |                                                                                                                                                                                                                                                                                |
   |                       |                       | A domain name can contain up to 10,000 characters. You can specify up to 100 domain names and separate them using commas (,).                                                                                                                                                  |
   |                       |                       |                                                                                                                                                                                                                                                                                |
   |                       |                       | The value can be one of the following:                                                                                                                                                                                                                                         |
   |                       |                       |                                                                                                                                                                                                                                                                                |
   |                       |                       | -  A common domain name contains 0 to 100 characters and consists of several labels separated by dots (.). Each label can contain a maximum of 63 characters, including letters, digits, and hyphens (-), and must start and end with a letter or digit. Example: www.test.com |
   |                       |                       | -  In addition to the requirements for common domain names, a wildcard domain name can start with an asterisk (*). Example: \*.test.com                                                                                                                                        |
   |                       |                       |                                                                                                                                                                                                                                                                                |
   |                       |                       | .. note::                                                                                                                                                                                                                                                                      |
   |                       |                       |                                                                                                                                                                                                                                                                                |
   |                       |                       |    -  This parameter is valid only when **type** is set to **server**.                                                                                                                                                                                                         |
   |                       |                       |    -  SNI certificates of a dedicated load balancer's listener can have up to 200 domain names.                                                                                                                                                                                |
   |                       |                       |    -  SNI certificates of a shared load balancer's listener can have up to 30 domain names.                                                                                                                                                                                    |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | private_key           | String                | Specifies the private key of the server certificate in PEM format.                                                                                                                                                                                                             |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | certificate           | String                | Specifies the public key of the server certificate or CA certificate used to authenticate the client. The value of parameter **type** determines whether a public key or CA certificate is required. Both types of certificates are in PEM format.                             |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | expire_time           | String                | Specifies the time when the certificate expired.                                                                                                                                                                                                                               |
   |                       |                       |                                                                                                                                                                                                                                                                                |
   |                       |                       | The UTC time is in *YYYY-MM-DD HH:MM:SS* format.                                                                                                                                                                                                                               |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | create_time           | String                | Specifies the time when the certificate was created.                                                                                                                                                                                                                           |
   |                       |                       |                                                                                                                                                                                                                                                                                |
   |                       |                       | The UTC time is in *YYYY-MM-DD HH:MM:SS* format.                                                                                                                                                                                                                               |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | update_time           | String                | Specifies the time when the certificate was updated.                                                                                                                                                                                                                           |
   |                       |                       |                                                                                                                                                                                                                                                                                |
   |                       |                       | The UTC time is in *YYYY-MM-DD HH:MM:SS* format.                                                                                                                                                                                                                               |
   +-----------------------+-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Example Request
---------------

-  Request example 1: Querying all certificates

   .. code-block:: text

      GET https://{Endpoint}/v2.0/lbaas/certificates

-  Example 2: Querying a certificate whose ID is ef4d341365754a959556576501791b19 or ed40e8ea9957488ea82de025e35b74c0

   .. code-block:: text

      GET https://{Endpoint}/v2.0/lbaas/certificates?id=ef4d341365754a959556576501791b19&id=ed40e8ea9957488ea82de025e35b74c0

Example Response
----------------

-  Example response 1

   .. code-block::

      {
          "certificates": [
              {
                  "certificate": "-----BEGIN CERTIFICATE-----\nMIIC4TCCAcmgAwIBAgICEREwDQYJKoZIhvcNAQELBQAwFzEVMBMGA1UEAxMMTXlD\nb21wYW55IENBMB4XDTE4MDcwMjEzMjU0N1oXDTQ1MTExNzEzMjU0N1owFDESMBAG\nA1UEAwwJbG9jYWxob3N0MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA\n0FQGzi3ucTX+DNud1p/b4XVM6I3rY7+Cfge5GMLDIUXIHXCfCgp19Z3807yNpLF5\nU0NqPQZKUrZz3rQeLN9mYiUTJZPutYlFDDbB8CtlgV+eyU9yYJslWx/Bm5kWNPh9\n7B9Yu9pbp2u6zDA99IC4ekKD93KuzxlnLmSle4Y3dbYwk0LpMDL6lfCHKt/W7jaS\nIAzlsxD+QM6l7QjhWJ+kUx+UkboOISjTe7E9XmDLJR7u8LRAQylYKy4zgnv1tn/K\ny09cxLKAFtgoZWQD2FAZJf9F7k1kYNwqITz3CPlLZUUn7yw3nkOOtLMI28IEv0Wy\nYd7CMJQkS1NPJBKNOGfR/wIDAQABozowODAhBgNVHREEGjAYggpkb21haW4uY29t\nhwQKuUvJhwR/AAABMBMGA1UdJQQMMAoGCCsGAQUFBwMBMA0GCSqGSIb3DQEBCwUA\nA4IBAQA8lMQJxaTey7EjXtRLSVlEAMftAQPG6jijNQuvIBQYUDauDT4W2XUZ5wAn\njiOyQ83va672K1G9s8n6xlH+xwwdSNnozaKzC87vwSeZKIOdl9I5I98TGKI6OoDa\nezmzCwQYtHBMVQ4c7Ml8554Ft1mWSt4dMAK2rzNYjvPRLYlzp1HMnI6hkjPk4PCZ\nwKnha0dlScati9CCt3UzXSNJOSLalKdHErH08Iqd+1BchScxCfk0xNITn1HZZGmI\n+vbmunok3A2lucI14rnsrcbkGYqxGikySN6B2cRLBDK4Y3wChiW6NVYtVqcx5/mZ\niYsGDVN+9QBd0eYUHce+77s96i3I\n-----END CERTIFICATE-----",
                  "create_time": "2017-02-25 09:35:27",
                  "expire_time": "2045-11-17 13:25:47",
                  "description": "description for certificate",
                  "domain": "www.elb.com",
                  "id": "23ef9aad4ecb463580476d324a6c71af",
                  "admin_state_up": true,
                  "tenant_id": "a31d2bdcf7604c0faaddb058e1e08819",
                  "name": "https_certificate",
                  "private_key":
      "-----BEGIN PRIVATE KEY-----\nMIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQDQVAbOLe5xNf4M\n253Wn9vhdUzojetjv4J+B7kYwsMhRcgdcJ8KCnX1nfzTvI2ksXlTQ2o9BkpStnPe\ntB4s32ZiJRMlk+61iUUMNsHwK2WBX57JT3JgmyVbH8GbmRY0+H3sH1i72luna7rM\nMD30gLh6QoP3cq7PGWcuZKV7hjd1tjCTQukwMvqV8Icq39buNpIgDOWzEP5AzqXt\nCOFYn6RTH5SRug4hKNN7sT1eYMslHu7wtEBDKVgrLjOCe/W2f8rLT1zEsoAW2Chl\nZAPYUBkl/0XuTWRg3CohPPcI+UtlRSfvLDeeQ460swjbwgS/RbJh3sIwlCRLU08k\nEo04Z9H/AgMBAAECggEAEIeaQqHCWZk/HyYN0Am/GJSGFa2tD60SXY2fUieh8/Hl\nfvCArftGgMaYWPSNCJRMXB7tPwpQu19esjz4Z/cR2Je4fTLPrffGUsHFgZjv5OQB\nZVe4a5Hj1OcgJYhwCqPs2d9i2wToYNBbcfgh8lSETq8YaXngBO6vES9LMhHkNKKr\nciu9YkInNEHu6uRJ5g/eGGX3KQynTvVIhnOVGAJvjTXcoU6fm7gYdHAD6jk9lc9M\nEGpfYI6AdHIwFZcT/RNAxhP82lg2gUJSgAu66FfDjMwQXKbafKdP3zq4Up8a7Ale\nkrguPtfV1vWklg+bUFhgGaiAEYTpAUN9t2DVIiijgQKBgQDnYMMsaF0r557CM1CT\nXUqgCZo8MKeV2jf2drlxRRwRl33SksQbzAQ/qrLdT7GP3sCGqvkxWY2FPdFYf8kx\nGcCeZPcIeZYCQAM41pjtsaM8tVbLWVR8UtGBuQoPSph7JNF3Tm/JH/fbwjpjP7dt\nJ7n8EzkRUNE6aIMHOFEeych/PQKBgQDmf1bMogx63rTcwQ0PEZ9Vt7mTgKYK4aLr\niWgTWHXPZxUQaYhpjXo6+lMI6DpExiDgBAkMzJGIvS7yQiYWU+wthAr9urbWYdGZ\nlS6VjoTkF6r7VZoILXX0fbuXh6lm8K8IQRfBpJff56p9phMwaBpDNDrfpHB5utBU\nxs40yIdp6wKBgQC69Cp/xUwTX7GdxQzEJctYiKnBHKcspAg38zJf3bGSXU/jR4eB\n1lVQhELGI9CbKSdzKM71GyEImix/T7FnJSHIWlho1qVo6AQyduNWnAQD15pr8KAd\nXGXAZZ1FQcb3KYa+2fflERmazdOTwjYZ0tGqZnXkEeMdSLkmqlCRigWhGQKBgDak\n/735uP20KKqhNehZpC2dJei7OiIgRhCS/dKASUXHSW4fptBnUxACYocdDxtY4Vha\nfI7FPMdvGl8ioYbvlHFh+X0Xs9r1S8yeWnHoXMb6eXWmYKMJrAoveLa+2cFm1Agf\n7nLhA4R4lqm9IpV6SKegDUkR4fxp9pPyodZPqBLLAoGBAJkD4wHW54Pwd4Ctfk9o\njHjWB7pQlUYpTZO9dm+4fpCMn9Okf43AE2yAOaAP94GdzdDJkxfciXKcsYr9IIuk\nfaoXgjKR7p1zERiWZuFF63SB4aiyX1H7IX0MwHDZQO38a5gZaOm/BUlGKMWXzuEd\n3fy+1rCUwzOp9LSjtJYf4ege\n-----END PRIVATE KEY-----",
                  "type": "server",
                  "update_time": "2017-02-25 09:35:27"
              }
          ],
          "instance_num": 1
      }

-  Example response 2

   .. code-block::

      {
          "certificates": [
              {
                  "description": "Push by SSL Certificate Manager",
                  "domain": null,
                  "id": "ed40e8ea9957488ea82de025e35b74c0",
                  "name": "certForSonar9",
                  "certificate": "-----BEGIN CERTIFICATE-----
      MIIFizCCBHOgAwIBAgIQBlQycV3bWsVsCttvv5rgRjANBgkqhkiG9w0BAQsFADBu
      MQswCQYDVQQGEwJVUzEVMBMGA1UEChMMRGlnaUNlcnQgSW5jMRkwFwYDVQQLExB3
      d3cuZGlnaWNlcnQuY29tMS0wKwYDVQQDEyRFbmNyeXB0aW9uIEV2ZXJ5d2hlcmUg
      RFYgVExTIENBIC0gRzEwHhcNMTgwNzEwMDAwMDAwWhcNMTkwNzEwMTIwMDAwWjAU
      MRIwEAYDVQQDEwlpY2UxMjMudGswggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEK
      AoIBAQCtTDlQMoAvyInR6X1dihhNwbdGesbMW6NZX7ffpj9XrB3KCqqlxzI4VmH9
      PntvrpLJNeolgLqDZZc4zKbUkmqxY1dvGDs41coKzdtc9Ig23GVK48wfesnk5r50
      afyU52R1JlSHDOhiDhHOSyhrOzc2GreLrByWKFUaAue6rTnyMbzQaSPtrTAqsURZ
      wcmJ6R3A6JwokOgxXBSu41ufPQiFkMgxygKxEBLzIJLjRqCXQHYoxbsTyolb6jwp
      w4H6vcRIEcFAgs98ApWRoEKjy7eOP3UUm05F+OkOvXhrlxEqIPm/rlwE0PmVlmm9
      DgBafYb3xT/MtT2VRSfCJQHgIcsdAgMBAAGjggJ9MIICeTAfBgNVHSMEGDAWgBRV
      dE+yck/1YLpQ0dfmUVyaAYca1zAdBgNVHQ4EFgQUEFavzYXBNbIHBchbaKcUKad+
      qCEwIwYDVR0RBBwwGoIJaWNlMTIzLnRrgg13d3cuaWNlMTIzLnRrMA4GA1UdDwEB
      /wQEAwIFoDAdBgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwTAYDVR0gBEUw
      QzA3BglghkgBhv1sAQIwKjAoBggrBgEFBQcCARYcaHR0cHM6Ly93d3cuZGlnaWNl
      cnQuY29tL0NQUzAIBgZngQwBAgEwgYEGCCsGAQUFBwEBBHUwczAlBggrBgEFBQcw
      AYYZaHR0cDovL29jc3AyLmRpZ2ljZXJ0LmNvbTBKBggrBgEFBQcwAoY+aHR0cDov
      L2NhY2VydHMuZGlnaWNlcnQuY29tL0VuY3J5cHRpb25FdmVyeXdoZXJlRFZUTFND
      QS1HMS5jcnQwCQYDVR0TBAIwADCCAQQGCisGAQQB1nkCBAIEgfUEgfIA8AB2AKS5
      CZC0GFgUh7sTosxncAo8NZgE+RvfuON3zQ7IDdwQAAABZIOnLCIAAAQDAEcwRQIh
      AJX6gCXNggPdfOFdDtZPzlYr64TTrR/+b9QKKhyJ2EjBAiAWgu3BG2QK9tWQXpUN
      IFadc0nvqmDovabg5nmRMan2mQB2AId1v+dZfPiMQ5lfvfNu/1aNR1Y2/0q1YMG0
      6v9eoIMPAAABZIOnLQEAAAQDAEcwRQIhAJVRe/7n88dD6KdhNrd4LdFjGARQNmta
      Y/K2dFDOXPSfAiBOLrWW8unHOL25RWHJU7Ost3XkNhQYtrLDJrnzo/9kZzANBgkq
      hkiG9w0BAQsFAAOCAQEAeqtX9cHmj4OnNAk0IGmF3nKS/u/UgGsY4EJfXwQY2bTZ
      PCkqxQOA6HEx59vJ+UilTojrNDi0WskRm/8SKBHtmRwzwX3ile8KiR6fFfQhPUtV
      XHZcTfAFo47c7axqon8vumMlEv1PxVImivQ446K7z3kGm34dhMYxS4Gz2gTl8IKt
      90OegejuhbAs5Wlvp1BK8HlYIb5+mw+cgkUC9KTALs5qVbWzogb0bS20KaYarGcu
      otcZAOMeJdBFWnpzhr1fxmjaNY4u4hrgPZSTU/iBjdHapoza3zAFfxysmGYqs9dR
      jFyxZeR4scz8GqSTFviNdH9jvtDJkdAC5hfMaB811Q==
      -----END CERTIFICATE-----
      -----BEGIN CERTIFICATE-----
      MIIEqjCCA5KgAwIBAgIQAnmsRYvBskWr+YBTzSybsTANBgkqhkiG9w0BAQsFADBh
      MQswCQYDVQQGEwJVUzEVMBMGA1UEChMMRGlnaUNlcnQgSW5jMRkwFwYDVQQLExB3
      d3cuZGlnaWNlcnQuY29tMSAwHgYDVQQDExdEaWdpQ2VydCBHbG9iYWwgUm9vdCBD
      QTAeFw0xNzExMjcxMjQ2MTBaFw0yNzExMjcxMjQ2MTBaMG4xCzAJBgNVBAYTAlVT
      MRUwEwYDVQQKEwxEaWdpQ2VydCBJbmMxGTAXBgNVBAsTEHd3dy5kaWdpY2VydC5j
      b20xLTArBgNVBAMTJEVuY3J5cHRpb24gRXZlcnl3aGVyZSBEViBUTFMgQ0EgLSBH
      MTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALPeP6wkab41dyQh6mKc
      oHqt3jRIxW5MDvf9QyiOR7VfFwK656es0UFiIb74N9pRntzF1UgYzDGu3ppZVMdo
      lbxhm6dWS9OK/lFehKNT0OYI9aqk6F+U7cA6jxSC+iDBPXwdF4rs3KRyp3aQn6pj
      pp1yr7IB6Y4zv72Ee/PlZ/6rK6InC6WpK0nPVOYR7n9iDuPe1E4IxUMBH/T33+3h
      yuH3dvfgiWUOUkjdpMbyxX+XNle5uEIiyBsi4IvbcTCh8ruifCIi5mDXkZrnMT8n
      wfYCV6v6kDdXkbgGRLKsR4pucbJtbKqIkUGxuZI2t7pfewKRc5nWecvDBZf3+p1M
      pA8CAwEAAaOCAU8wggFLMB0GA1UdDgQWBBRVdE+yck/1YLpQ0dfmUVyaAYca1zAf
      BgNVHSMEGDAWgBQD3lA1VtFMu2bwo+IbG8OXsj3RVTAOBgNVHQ8BAf8EBAMCAYYw
      HQYDVR0lBBYwFAYIKwYBBQUHAwEGCCsGAQUFBwMCMBIGA1UdEwEB/wQIMAYBAf8C
      AQAwNAYIKwYBBQUHAQEEKDAmMCQGCCsGAQUFBzABhhhodHRwOi8vb2NzcC5kaWdp
      Y2VydC5jb20wQgYDVR0fBDswOTA3oDWgM4YxaHR0cDovL2NybDMuZGlnaWNlcnQu
      Y29tL0RpZ2lDZXJ0R2xvYmFsUm9vdENBLmNybDBMBgNVHSAERTBDMDcGCWCGSAGG
      /WwBAjAqMCgGCCsGAQUFBwIBFhxodHRwczovL3d3dy5kaWdpY2VydC5jb20vQ1BT
      MAgGBmeBDAECATANBgkqhkiG9w0BAQsFAAOCAQEAK3Gp6/aGq7aBZsxf/oQ+TD/B
      SwW3AU4ETK+GQf2kFzYZkby5SFrHdPomunx2HBzViUchGoofGgg7gHW0W3MlQAXW
      M0r5LUvStcr82QDWYNPaUy4taCQmyaJ+VB+6wxHstSigOlSNF2a6vg4rgexixeiV
      4YSB03Yqp2t3TeZHM9ESfkus74nQyW7pRGezj+TC44xCagCQQOzzNmzEAP2SnCrJ
      sNE2DpRVMnL8J6xBRdjmOsC3N6cQuKuRXbzByVBjCqAA8t1L0I+9wXJerLPyErjy
      rMKWaBFLmfK/AHNF4ZihwPGOc7w6UHczBZXH5RFzJNnww+WnKuTPI0HfnVH8lg==
      -----END CERTIFICATE-----",
                  "type": "server",
                  "create_time": "2019-03-03 16:32:30",
                  "private_key": "-----BEGIN RSA PRIVATE KEY-----
      MIIEpQIBAAKCAQEArUw5UDKAL8iJ0el9XYoYTcG3RnrGzFujWV+336Y/V6wdygqq
      pccyOFZh/T57b66SyTXqJYC6g2WXOMym1JJqsWNXbxg7ONXKCs3bXPSINtxlSuPM
      H3rJ5Oa+dGn8lOdkdSZUhwzoYg4Rzksoazs3Nhq3i6wclihVGgLnuq058jG80Gkj
      7a0wKrFEWcHJiekdwOicKJDoMVwUruNbnz0IhZDIMcoCsRAS8yCS40agl0B2KMW7
      E8qJW+o8KcOB+r3ESBHBQILPfAKVkaBCo8u3jj91FJtORfjpDr14a5cRKiD5v65c
      BND5lZZpvQ4AWn2G98U/zLU9lUUnwiUB4CHLHQIDAQABAoIBAGs5rISompP2OwA8
      virwVRVXdPUQ5oxvbuTPys+A59RxVIU8kFW+qJ4fJMYysOFrXLtOtq+5tK20YBru
      1ZLVfVqAowrELXB/J2ID+WTMkLORLsNlq1kW+nC9LL6PDY98lLW/n7FoFSkGl5HT
      AxFGNGUvpr2vIojuL6nGfmcM47uscJ9aP6IJxr4p70dhPVjZBdnMnXYwRkB3dZt/
      E0B/p8J5i3oo5Rucv4DOfB+01wXGAVyx5/zce+NZdhyrivkj3hHV55SxGhVWzWhj
      a3dAlbpKwYgfILj0inRdJYmIjBdbGb2HFix7+ncBg8B2oerJXC6/fANwRGu5/LZU
      5xuPVWkCgYEA6an8TY1unIGLYL5aBJ16Tx4usqMyTXr/T4zkQyftRPMt+ZuxVQHl
      GHsg7XvLFNd04MBZXtkZXaYVcpOm7OUYcl0i9ZAkWXXoXcBtn1Oom3gz/7RjAUnp
      k+myvxCUSQ2JSz4u3QBtyPVyYNyBFXrKqdKfcYyG85+yQVHBNMVrdvMCgYEAvd0C
      hFpm83ha+VQp+9XN1DYZNUyqhibj/E3X9jAn+gDbzlKxw/D9en2RIlQYUrl8+il8
      QKk4cfOxJYStQfxptz8QBPVeLajDN67zJ0Rk8AB50HHHcNSU8uFkaO8KxsyVjbLS
      +JltqfJAEraXLinbp1Fxcg9DsQdMd6cw2DmrWa8CgYEA1UjJOUzo80i4HYWDC4Vn
      OEK3o22do+WqmEVlsfsG9BH5HEdGVe7V3EO/6aY+1/ZXBDPvH8mRAs9v8lbeXow7
      hWCIYZfB5jre8HyOU4l8dPUCmdxhJrL913rRIuASSqBlet32ztnuXCnWzp1X4nBj
      /yF3UqFQKZ7SihcDAZVWo4sCgYEAj7al/BcNzIcynX2mldhdh583b4/Ll+YCNm2Z
      5eDHscZKmx8fLcjRpZE8dXagPqXmwtj6E1vDvQWP9m06VDNCthFHB+nO0tLmidSk
      evmbScuiaTRmmbJf2IThY0hlqNsc7PgKF2DTkIstEr0hLDFE8Z6FN6f0PiDfMcbd
      Ax6L5EMCgYEA0+qhuQftKQkGdbXX9r3H8N0TVh27ByfL3kKVYy0dUJMvsOAq6d97
      8mEhYhrYt88f1sFsPM7G09XpCcBXwiKxw8+CDt9auD4r1snBnILpqMPmanF4UDXH
      L7s+4it+nIQy24P6g1PihtzsM+HD2UCErBiYUJdRK8Q9GGHdZojFk9Y=
      -----END RSA PRIVATE KEY-----
      ",
                  "update_time": "2019-03-03 16:32:30",
                  "admin_state_up": true,
                  "tenant_id": "601240b9c5c94059b63d484c92cfe308",
                  "expire_time": "2019-07-10 12:00:00"
              },
              {
                  "description": null,
                  "domain": "www.elb.com",
                  "id": "ef4d341365754a959556576501791b19",
                  "name": "certificate_28b824c8bbee419992fb7974b2911c72",
                  "certificate": "-----BEGIN CERTIFICATE-----
      MIIDpTCCAo2gAwIBAgIJAKdmmOBYnFvoMA0GCSqGSIb3DQEBCwUAMGkxCzAJBgNV
      BAYTAnh4MQswCQYDVQQIDAJ4eDELMAkGA1UEBwwCeHgxCzAJBgNVBAoMAnh4MQsw
      CQYDVQQLDAJ4eDELMAkGA1UEAwwCeHgxGTAXBgkqhkiG9w0BCQEWCnh4QDE2My5j
      b20wHhcNMTcxMjA0MDM0MjQ5WhcNMjAxMjAzMDM0MjQ5WjBpMQswCQYDVQQGEwJ4
      eDELMAkGA1UECAwCeHgxCzAJBgNVBAcMAnh4MQswCQYDVQQKDAJ4eDELMAkGA1UE
      CwwCeHgxCzAJBgNVBAMMAnh4MRkwFwYJKoZIhvcNAQkBFgp4eEAxNjMuY29tMIIB
      IjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAwZ5UJULAjWr7p6FVwGRQRjFN
      2s8tZ/6LC3X82fajpVsYqF1xqEuUDndDXVD09E4u83MS6HO6a3bIVQDp6/klnYld
      iE6Vp8HH5BSKaCWKVg8lGWg1UM9wZFnlryi14KgmpIFmcu9nA8yV/6MZAe6RSDmb
      3iyNBmiZ8aZhGw2pI1YwR+15MVqFFGB+7ExkziROi7L8CFCyCezK2/oOOvQsH1dz
      Q8z1JXWdg8/9Zx7Ktvgwu5PQM3cJtSHX6iBPOkMU8Z8TugLlTqQXKZOEgwajwvQ5
      mf2DPkVgM08XAgaLJcLigwD513koAdtJd5v+9irw+5LAuO3JclqwTvwy7u/YwwID
      AQABo1AwTjAdBgNVHQ4EFgQUo5A2tIu+bcUfvGTD7wmEkhXKFjcwHwYDVR0jBBgw
      FoAUo5A2tIu+bcUfvGTD7wmEkhXKFjcwDAYDVR0TBAUwAwEB/zANBgkqhkiG9w0B
      AQsFAAOCAQEAWJ2rS6Mvlqk3GfEpboezx2J3X7l1z8Sxoqg6ntwB+rezvK3mc9H0
      83qcVeUcoH+0A0lSHyFN4FvRQL6X1hEheHarYwJK4agb231vb5erasuGO463eYEG
      r4SfTuOm7SyiV2xxbaBKrXJtpBp4WLL/s+LF+nklKjaOxkmxUX0sM4CTA7uFJypY
      c8Tdr8lDDNqoUtMD8BrUCJi+7lmMXRcC3Qi3oZJW76ja+kZA5mKVFPd1ATih8TbA
      i34R7EQDtFeiSvBdeKRsPp8c0KT8H1B4lXNkkCQs2WX5p4lm99+ZtLD4glw8x6Ic
      i1YhgnQbn5E0hz55OLu5jvOkKQjPCW+8Kg==
      -----END CERTIFICATE-----",
                  "type": "server",
                  "create_time": "2018-09-28 03:00:47",
                  "private_key": "-----BEGIN RSA PRIVATE KEY-----
      MIIEowIBAAKCAQEAwZ5UJULAjWr7p6FVwGRQRjFN2s8tZ/6LC3X82fajpVsYqF1x
      qEuUDndDXVD09E4u83MS6HO6a3bIVQDp6/klnYldiE6Vp8HH5BSKaCWKVg8lGWg1
      UM9wZFnlryi14KgmpIFmcu9nA8yV/6MZAe6RSDmb3iyNBmiZ8aZhGw2pI1YwR+15
      MVqFFGB+7ExkziROi7L8CFCyCezK2/oOOvQsH1dzQ8z1JXWdg8/9Zx7Ktvgwu5PQ
      M3cJtSHX6iBPOkMU8Z8TugLlTqQXKZOEgwajwvQ5mf2DPkVgM08XAgaLJcLigwD5
      13koAdtJd5v+9irw+5LAuO3JclqwTvwy7u/YwwIDAQABAoIBACU9S5fjD9/jTMXA
      DRs08A+gGgZUxLn0xk+NAPX3LyB1tfdkCaFB8BccLzO6h3KZuwQOBPv6jkdvEDbx
      Nwyw3eA/9GJsIvKiHc0rejdvyPymaw9I8MA7NbXHaJrY7KpqDQyk6sx+aUTcy5jg
      iMXLWdwXYHhJ/1HVOo603oZyiS6HZeYU089NDUcX+1SJi3e5Ke0gPVXEqCq1O11/
      rh24bMxnwZo4PKBWdcMBN5Zf/4ij9vrZE+fFzW7vGBO48A5lvZxWU2U5t/OZQRtN
      1uLOHmMFa0FIF2aWbTVfwdUWAFsvAOkHj9VV8BXOUwKOUuEktdkfAlvrxmsFrO/H
      yDeYYPkCgYEA/S55CBbR0sMXpSZ56uRn8JHApZJhgkgvYr+FqDlJq/e92nAzf01P
      RoEBUajwrnf1ycevN/SDfbtWzq2XJGqhWdJmtpO16b7KBsC6BdRcH6dnOYh31jgA
      vABMIP3wzI4zSVTyxRE8LDuboytF1mSCeV5tHYPQTZNwrplDnLQhywcCgYEAw8Yc
      Uk/eiFr3hfH/ZohMfV5p82Qp7DNIGRzw8YtVG/3+vNXrAXW1VhugNhQY6L+zLtJC
      aKn84ooup0m3YCg0hvINqJuvzfsuzQgtjTXyaE0cEwsjUusOmiuj09vVx/3U7siK
      Hdjd2ICPCvQ6Q8tdi8jV320gMs05AtaBkZdsiWUCgYEAtLw4Kk4f+xTKDFsrLUNf
      75wcqhWVBiwBp7yQ7UX4EYsJPKZcHMRTk0EEcAbpyaJZE3I44vjp5ReXIHNLMfPs
      uvI34J4Rfot0LN3n7cFrAi2+wpNo+MOBwrNzpRmijGP2uKKrq4JiMjFbKV/6utGF
      Up7VxfwS904JYpqGaZctiIECgYA1A6nZtF0riY6ry/uAdXpZHL8ONNqRZtWoT0kD
      79otSVu5ISiRbaGcXsDExC52oKrSDAgFtbqQUiEOFg09UcXfoR6HwRkba2CiDwve
      yHQLQI5Qrdxz8Mk0gIrNrSM4FAmcW9vi9z4kCbQyoC5C+4gqeUlJRpDIkQBWP2Y4
      2ct/bQKBgHv8qCsQTZphOxc31BJPa2xVhuv18cEU3XLUrVfUZ/1f43JhLp7gynS2
      ep++LKUi9D0VGXY8bqvfJjbECoCeu85vl8NpCXwe/LoVoIn+7KaVIZMwqoGMfgNl
      nEqm7HWkNxHhf8A6En/IjleuddS1sf9e/x+TJN1Xhnt9W6pe7Fk1
      -----END RSA PRIVATE KEY-----",
                  "update_time": "2018-09-28 03:00:47",
                  "admin_state_up": true,
                  "tenant_id": "601240b9c5c94059b63d484c92cfe308",
                  "expire_time": "2020-12-03 03:42:49"
              }
          ],
          "instance_num": 2
      }

Status Code
-----------

For details, see :ref:`Status Codes <elb_gc_1102>`.
