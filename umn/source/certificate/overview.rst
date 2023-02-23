:original_name: elb_ug_zs_0001.html

.. _elb_ug_zs_0001:

Overview
========

ELB supports two types of certificates. If you need an HTTPS listener, you need to bind a server certificate to it. To enable mutual authentication, you also need to bind a CA certificate to the listener.

-  **Server certificate**: used for SSL handshake negotiations if an HTTPS listener is used. Both the certificate content and private key are required.
-  **CA certificate**: issued by a certificate authority (CA) and used to verify the certificate issuer. If HTTPS mutual authentication is required, HTTPS connections can be established only when the client provides a certificate issued by a specific CA.

Precautions
-----------

-  A certificate can be used by multiple load balancers but only needs to be uploaded to each load balancer once.
-  If a certificate is used for SNI, you need to specify a domain name for the certificate, and the domain name must be the same as that in the certificate.
-  For each certificate type, a listener can have only one certificate by default, but a certificate can be bound to more than one listener. If SNI is enabled for the listener, multiple server certificates can be bound.
-  Only original certificates are supported. That is to say, you cannot encrypt your certificates.
-  You do not need to configure certificates for both the shared load balancer and the associated backend servers. If you configure a certificate for backend servers, HTTPS listeners cannot be added to the load balancer. In this case, you can add a TCP listener to transparently transmit HTTPS traffic to backend servers. This restriction does not apply to dedicated load balancers.
-  You can use self-signed certificates. However, note that self-signed certificates pose security risks. Therefore, it is recommended that you use certificates issued by third parties.
-  ELB supports certificates only in PEM format. If you have a certificate in any other format, you must convert it to a PEM-encoded certificate.
-  Currently, ELB does not check certificate validity.
-  If a certificate has expired, you need to manually replace or delete it.
