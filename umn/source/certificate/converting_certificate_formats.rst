Converting Certificate Formats
==============================

Scenarios
---------

ELB supports certificates only in PEM format. If you have a certificate in any other format, you must convert it to a PEM-encoded certificate. There are some common methods for converting a certificate from any other format to PEM.

From DER to PEM
---------------

The DER format is usually used on a Java platform.

Run the following command to convert the certificate format:

.. code::

   openssl x509 -inform der -in certificate.cer -out certificate.pem

Run the following command to convert the private key format:

.. code::

   openssl rsa -inform DER -outform PEM -in privatekey.der -out privatekey.pem

From P7B to PEM
---------------

The P7B format is usually used by Windows Server and Tomcat.

Run the following command to convert the certificate format:

.. code::

   openssl pkcs7 -print_certs -in incertificate.p7b -out outcertificate.cer

From PFX to PEM
---------------

The PFX format is usually used by Windows Server.

Run the following command to convert the certificate format:

.. code::

   openssl pkcs12 -in certname.pfx -nokeys -out cert.pem

Run the following command to convert the private key format:

.. code::

   openssl pkcs12 -in certname.pfx -nocerts -out key.pem -nodes
