var express = require('express');
var router = express.Router();

/* destroy session */
router.get('/destroySession', function(req, res, next) {
  req.session.destroy(function(err) {});
  res.send('Destroyed session');
});

/* take session */
router.get('/takeSession', function(req, res, next) {
  res.send('value of session: ' + req.session.session01)
});

/* create session */
router.get('/createSession', function(req, res, next) {
  req.session.session01 = 'session01';
  res.send('successfully');
});

/* remove cookie */
router.get('/remove', function(req, res, next) {
  res.clearCookie('ID');
  res.clearCookie('IDP');
  res.render('testCookie', { title: 'CREATE COOKIE' , order : 'Da xoa cookie ID', product : 'Da xoa cookie IDP'});
});

/* take cookie */
router.get('/ProductInfo', function(req, res, next) {
  res.render('testCookie', { title: 'CREATE COOKIE' , order : 'OrderID: ' + req.cookies.ID, product : 'ProductID: ' + req.cookies.IDP});
});

/* create cookie */
router.get('/:productID.:orderID', function(req, res, next) {
  res.cookie('ID', req.params.orderID, {maxAge : 1000})
  res.cookie('IDP', req.params.productID)
  res.render('testCookie', { title: 'CREATE COOKIE' , order : 'OrderID: ' + req.cookies.ID, product : 'ProductID: ' + req.cookies.IDP});
});

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

module.exports = router;
