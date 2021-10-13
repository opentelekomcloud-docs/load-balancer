Creating and Managing a Certificate
===================================

Scenarios
---------

To enable authentication for securing data transmission over HTTPS, ELB allows you to deploy certificates on load balancers.

|image1|

-  A certificate can be bound to only one type of load balancer. Ensure that you have selected the correct type.

Creating a Certificate
----------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image2| and select the desired region and project.
#. Hover on |image3| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. In the navigation pane on the left, choose **Certificates**.
#. Click **Create Certificate**. In the **Create Certificate** dialog box, configure the following parameters:

   -  **Certificate Name**

   -  **Certificate Type**

      -  **Server certificate**: used for SSL handshake negotiations if an HTTPS listener is used. Both the certificate content and private key are required.
      -  **CA certificate**: issued by a certificate authority (CA) and used to verify the certificate issuer. If HTTPS mutual authentication is required, HTTPS connections can be established only when the client provides a certificate issued by a specific CA.

   -  **Domain Name**: If the certificate is used for SNI, a domain name must be specified.

   -  **Certificate Content**: The content must be in PEM format.

      Click **Upload** and select the certificate to be uploaded. Ensure that your browser is of the latest version.

      The format of the certificate body is as follows:

      .. code::

         -----BEGIN CERTIFICATE-----
         Base64–encoded certificate
         -----END CERTIFICATE-----

   -  **Private Key**

      Click **Upload** and select the private key to be uploaded. Ensure that your browser is of the latest version.

      **Private Key**: This must be an unencrypted private key. The format is as follows:

      .. code::

         -----BEGIN PRIVATE KEY-----
         [key]
         -----END PRIVATE KEY-----

      |image4|

      If there is a certificate chain, you need to configure the certificates in the following sequence: sub-certificate (server certificate), intermediate certificate, and root certificate. If the root certificate has been preset on the server and is not contained in the issued certificates, first configure the sub-certificate (server certificate) and then the intermediate certificate.

      For example, if a CA issued a private key **private.key** and two certificates: a sub-certificate (server certificate) **server.cer** and an intermediate certificate **mid.crt**, paste the content of **server.cer** in the **Certificate Content** text box, press **Enter**, then paste the content of **mid.crt** in the **Certificate Content** text box, and paste the content of **private.key** in the **Private Key** text box to make the entire certificate chain take effect. The format of the certificate body in a certificate chain is as follows:

      Certificate body

      .. code::

         -----BEGIN CERTIFICATE-----
         Content of the server certificate file server.cer
         -----END CERTIFICATE-----
         -----BEGIN CERTIFICATE-----
         Content of the intermediate certificate file mid.crt
         -----END CERTIFICATE-----

      Private key

      .. code::

         -----BEGIN PRIVATE KEY-----
         Content of the private key file private.key
         -----END PRIVATE KEY-----

   -  **Domain Name**

      If the created certificate is used for SNI, you need to specify a domain name. Only one domain name can be specified for each certificate, and the domain name must be the same as that in the certificate.

   -  **Description**

6. Click **OK**.

Binding a Certificate
---------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image5| and select the desired region and project.
#. Hover on |image6| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Under **Listeners**, click **Add Listener**.
#. In the **Add Listener** dialog box, configure the parameters. When **Frontend Protocol** is set to **HTTPS**, a server certificate must be bound to the listener.
#. Click **OK**.

Deleting a Certificate
----------------------

Only certificates that are not in use can be deleted.

#. Log in to the management console.
#. In the upper left corner of the page, click |image7| and select the desired region and project.
#. Hover on |image8| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. In the navigation pane on the left, choose **Certificates**.
#. Locate the certificate and click **Delete** in the **Operation** column.
#. Click **Yes**.

Modifying a Certificate
-----------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image9| and select the desired region and project.
#. Hover on |image10| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. In the navigation pane on the left, choose **Certificates**.
#. Locate the certificate and click **Modify** in the **Operation** column.
#. Modify the parameters as required.
#. Click **OK**.

.. |image1| image:: /images/note_3.0-en-us.png
.. |image2| image:: /images/en-us_image_0241356603.png

.. |image3| image:: /images/en-us_image_0000001120894978.png

.. |image4| image:: /images/note_3.0-en-us.png
.. |image5| image:: /images/en-us_image_0241356603.png

.. |image6| image:: /images/en-us_image_0000001120894978.png

.. |image7| image:: /images/en-us_image_0241356603.png

.. |image8| image:: /images/en-us_image_0000001120894978.png

.. |image9| image:: /images/en-us_image_0241356603.png

.. |image10| image:: /images/en-us_image_0000001120894978.png

