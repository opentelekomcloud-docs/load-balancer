:original_name: elb_ug_jt_0021.html

.. _elb_ug_jt_0021:

SNI Certificate (for HTTPS Listeners)
=====================================

Scenarios
---------

If you have an application that can be accessed through multiple domain names and each domain name uses a different certificate, you can enable Server Name Indication (SNI) when you add an HTTPS listener.

SNI, an extension to Transport Layer Security (TLS), enables a server to present multiple certificates on the same IP address and port number. SNI allows the client to indicate the domain name of the website while sending an SSL handshake request. Once receiving the request, the load balancer queries the right certificate based on the hostname or domain name and returns the certificate to the client. If no certificate is found, the load balancer will return the default certificate.

A maximum of 30 SNI certificates can be bound to each HTTPS listener.

Prerequisites
-------------

You have created a certificate by performing the operations in :ref:`Creating, Modifying, or Deleting a Certificate <elb_ug_zs_0004>`.

-

   .. note::

      -  You must specify at least one domain name for each certificate. The domain name must be the same as that in the certificate.
      -  If a certificate has expired, you need to manually replace or delete it by following the instructions in :ref:`Replacing a Certificate <elb_ug_zs_0005>`.

Procedure
---------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

4. Locate the load balancer and click its name.
5. Click **Listeners** and locate the listener. In the **Basic Information** area, click **Configure** on the right of **SNI**.
6. Enable SNI and select the SNI certificate.
7. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001417088430.png
