SNI Certificate (for HTTPS Listeners)
=====================================

Scenarios
---------

If you have an application that can be accessed through multiple domain names and each domain name uses a different certificate, you can enable SNI when you add an HTTPS listener.

SNI is an extension to TLS and enables a server to present multiple certificates on the same IP address and TCP port number. This allows multiple secure (HTTPS) websites (or any other service over TLS) to be served by the same IP address without requiring all websites to use the same certificate. SNI allows the client to submit the domain name information while sending an SSL handshake request. Once the load balancer receives the request, it queries the right certificate based on the domain name and returns the corresponding certificate to the client. If no certificate is found, the load balancer will return a default certificate.

A maximum of 30 SNI certificates can be configured for each listener.

Prerequisites
-------------

You have created a certificate by performing the operations in `Creating and Managing a Certificate <en-us_elb_03_0005.html>`__.

-  |image1|

   Only one domain name can be specified for each certificate. Wildcard-domain certificates are supported.

Procedure
---------

#. Log in to the management console.
#. In the upper left corner of the page, click |image2| and select the desired region and project.
#. Hover on |image3| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

4. Locate the load balancer and click its name.
5. Click **Listeners**.

   -  For a shared load balancer, locate the listener and click **Configure** on the right of **SNI**.
   -  For a classic load balancer, click **Listeners**, locate the listener, and click **Modify** in the **Operation** column. In the **Modify Listener** dialog box, modify the parameters as needed.

6. Enable SNI and select the SNI certificate to be used.
7. Click **OK**.

.. |image1| image:: /images/note_3.0-en-us.png
.. |image2| image:: /images/en-us_image_0241356603.png

.. |image3| image:: /images/en-us_image_0000001120894978.png

